// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL
// Usable Baud Rate ... 9600 14400 19200 28800 38400 57600 2%
#define BAUD 19200
// Use with $ picocom -b 19200 /dev/ttyUSB0
#define BUFSIZE 120
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <string.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "config.h"

static void uart_init(void) {
  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= (1 << U2X0);
#else
  UCSR0A &= ~(1 << U2X0);
#endif
  /* async, non-parity, 1-bit stop, 8-bit data */
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
  /* tx/rx enable */
  UCSR0B = _BV(TXEN0) | _BV(RXEN0);
  // All Data Direction Register for input
  DDRB = DDRC = DDRD = 0;
  // pull-up for all
  PORTB = PORTC = PORTD = 0xff;
}


static void uart_putchar_raw(char c) {
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
}

static void uart_putchar(char c) {
  if (c == '\n') {
    uart_putchar_raw('\r');
  }
    uart_putchar_raw(c);
}

static void uart_put_nl(void) { uart_putchar('\n'); }

static void uart_put_bs(void) { uart_putchar_raw('\b'); }

static void uart_put_sp(void) { uart_putchar_raw(' '); }

static void uart_puts(char *s) {
  char c;
  while (1) {
    c = *s++;
    if (c == '\0') break;
    uart_putchar(c);
  }
}

static void uart_puts_P(PGM_P s) {
  char c;
  while (1) {
    c = pgm_read_byte(s++);
    if (c == '\0') break;
    uart_putchar(c);
  }
}

static void uart_put_byte(char c) {
  for (uint8_t i = 0; i < 8; i++) {
    uart_putchar_raw((c & (char)0x80) ? '1' : '0');
    c = c << 1;
  }
}

static void uart_put_byte_hex(char c) {
  uint8_t cx;
  cx = c >> 4;
  uart_putchar_raw((cx > (uint8_t)9) ? cx + 'A' - (uint8_t)10 : cx + '0');
  cx = (uint8_t)c & (uint8_t)0xf;
  uart_putchar_raw((cx > (uint8_t)9) ? cx + 'A' - (uint8_t)10 : cx + '0');
}

static char uart_getchar(void) {
  char c;
  loop_until_bit_is_set(UCSR0A, RXC0);
  if (UCSR0A & (_BV(FE0) | _BV(DOR0))) {
    // ERR | EOF --> treat as \n
    c = UDR0;
    c = '\n';
  } else {
    c = UDR0;
    if (c == '\r' || c == (char)0x1b) c = '\n';  // CR, ESC -> NL
  }
  return c;
}

//
// readline from uart with TAB/BS/^W/^U support
//
static void uart_ngets(char *s, uint8_t n) {
  char c;
  char *xs;
  uint8_t i;
  xs = s;
  i = 0; /* 0 ... n-1 */
  while (1) {
    c = uart_getchar();
    if (i >= n - 1 || c == '\n') {
      c = '\0';
      *xs = c;
      uart_put_nl();
      break;
    } else if (c == '\b' || c == 0x7f) {
      if (i > 0) {
        uart_put_bs();
        uart_put_sp();
        uart_put_bs();
        xs--;
        i--;
      }
    } else if (c == ('W' & 0x1f)) {
      while (xs > s && *(xs - 1) == ' ') {
        uart_put_bs();
        xs--;
        i--;
      }
      while (xs > s && *(xs - 1) != ' ') {
        uart_put_bs();
        uart_put_sp();
        uart_put_bs();
        xs--;
        i--;
      }
    } else if (c == ('U' & 0x1f)) {
      while (xs > s) {
        uart_put_bs();
        uart_put_sp();
        uart_put_bs();
        xs--;
        i--;
      }
    } else if (c == '\t') {
      do {
        uart_put_sp();
        *xs = ' ';
        xs++;
        i++;
      } while (i < n - 1 && (i % 8) != 0);
      if (i >= n - 1) {
        c = '\0';
        *xs = c;
        break;
      }
    } else if (c >= ' ' && c <= '~') {
      *xs = c;
      uart_putchar_raw(c);
      xs++;
      i++;
    } else {
      uart_puts_P(PSTR("\nERROR: "));
      uart_put_byte_hex(c);
      uart_put_nl();
    }
  }
}

#ifdef M328P
static void uart_put_m328p_pins(void) {
  uart_puts_P(PSTR("DDR = "));
  uart_put_byte(DDRB);
  uart_put_sp();
  uart_put_byte(DDRC);
  uart_put_sp();
  uart_put_byte(DDRD);
  uart_put_nl();
  uart_puts_P(PSTR("PORT= "));
  uart_put_byte(PORTB);
  uart_put_sp();
  uart_put_byte(PORTC);
  uart_put_sp();
  uart_put_byte(PORTD);
  uart_put_nl();
  uart_puts_P(PSTR("PIN = "));
  uart_put_byte(PINB);
  uart_put_sp();
  uart_put_byte(PINC);
  uart_put_sp();
  uart_put_byte(PIND);
  uart_put_nl();
  uart_put_nl();
}
#endif

static void uart_put_pins(void) {
#ifdef M328P
  uart_put_m328p_pins();
#endif
}

//
// binary to byte
//
// bit order
//  76543210
//
static uint8_t bin2byte(char *s) {
  uint8_t n = 0;
  int8_t i = 7;
  do {
    if (*s == '1') {
      n |= 1;
    } else if (*s == 0) {
      break;
    }
    ++s;
    n = n << 1;
  } while (i-- > 0);
  return n;
}

static uint8_t hex2byte(char *s) {
  uint8_t n = 0;
  int8_t i = 2;
  do {
    if (*s >= '0' && *s >= '9') {
      n |= *s - '0';
    } else if (*s >= 'A' && *s >= 'F') {
      n |= *s - 'A' + 10;
    } else if (*s >= 'a' && *s >= 'f') {
      n |= *s - 'a' + 10;
    } else if (*s == 0) {
      break;
    }
    ++s;
    n = n << 4;
  } while (i-- > 0);
  return n;
}

#ifdef WORD
static uint16_t hex2word(char *s) {
  uint16_t n = 0;
  int8_t i = 4;
  do {
    if (*s >= '0' && *s >= '9') {
      n |= *s - '0';
    } else if (*s >= 'A' && *s >= 'F') {
      n |= *s - 'A' + 10;
    } else if (*s >= 'a' && *s >= 'f') {
      n |= *s - 'a' + 10;
    } else if (*s == 0) {
      break;
    }
    ++s;
    n = n << 4;
  } while (i-- > 0);
  return n;
}
#endif

//
// What to chose for prefix (many taken)
//
// Hexadecimal     default, prefix $
// Binary                   prefix %
//
static uint8_t str2byte(char *s) {
  uint8_t n = 0;
  if (*s == '%') {
    s++;
    n = bin2byte(s);
  } else if (*s == '$') {
    s++;
    n = hex2byte(s);
  } else {
    n = hex2byte(s);
  }
  return n;
}

int main(void) {
  char s[BUFSIZE];
  char *t1;
  char *t2;
  char *t3;
  uart_init();
  uart_puts_P(PSTR("Hello world!\n"));
  while (1) {
    uart_puts("--------------\n");
#ifdef DEBUG_PINS
    uart_put_pins();
#endif
    s[0] = '\0';
    uart_ngets(s, BUFSIZE);
    uart_put_nl();
#ifdef DEBUG_GETS
    uart_puts(s);
    uart_put_nl();
#endif
    t1 = strtok(s, " ");
    t2 = strtok(NULL, " ");
    t3 = strtok(NULL, " ");
#ifdef DEBUG_ARGS
      uart_puts_P(PSTR(">> *t1 == |"));
      uart_puts(t1);
      uart_putchar('|');
      uart_put_nl();
      uart_puts_P(PSTR(">> *t2 == |"));
      uart_puts(t2);
      uart_putchar('|');
      uart_put_nl();
      uart_puts_P(PSTR(">> *t3 == |"));
      uart_puts(t3);
      uart_putchar('|');
      uart_put_nl();
#endif
    // do nothing
    if (!strcmp(t1, "r")) { /* read byte:    reg*/
      uart_puts_P(PSTR("**** ****\n"));
      uart_put_byte_hex(str2byte(t2));
      uart_put_nl();
    } else if (strcmp(t1, "w")) {  /* write byte:   reg val */
    } else if (strcmp(t1, "s")) {  /* scan matrix:  reg */
    } else if (strcmp(t1, "t0")) { /* toggle bit 0: reg */
    } else if (strcmp(t1, "t1")) { /* toggle bit 1: reg */
    } else if (strcmp(t1, "t2")) { /* toggle bit 2: reg */
    } else if (strcmp(t1, "t3")) { /* toggle bit 3: reg */
    } else if (strcmp(t1, "t4")) { /* toggle bit 4: reg */
    } else if (strcmp(t1, "t5")) { /* toggle bit 5: reg */
    } else if (strcmp(t1, "t6")) { /* toggle bit 6: reg */
    } else if (strcmp(t1, "t7")) { /* toggle bit 7: reg */
    }
    uart_puts("--------------\n");
  }
}
