// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL
// Usable Baud Rate ... 4800 9600 14400 19200 28800 38400 57600
#define BAUD 19200
// $ picocom -b 19200 /dev/ttyUSB0
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <util/setbaud.h>

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
}

int uart_putchar(char c, FILE *stream) {
  if (c == '\n') {
    uart_putchar('\r', stream);
  }
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}

int uart_getchar(FILE *stream) {
  uint8_t c;
  loop_until_bit_is_set(UCSR0A, RXC0);
  if (UCSR0A & _BV(FE0)) return _FDEV_EOF;
  if (UCSR0A & _BV(DOR0)) return _FDEV_ERR;
  c = UDR0;
  if (c == '\r') c = '\n';
  uart_putchar(c, stream);
  return c;
}

FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

#define RX_BUFSIZE 100
#define BIT5HI 0b00100000
int main(void) {
  char buf[RX_BUFSIZE], a1[RX_BUFSIZE / 2], a2[RX_BUFSIZE / 2];
  uart_init();
  stdout = stdin = &uart_str;
  // For Data Direction Register of port B, set 5 pin as output for LED
  DDRB = BIT5HI;
  DDRC = 0;
  DDRD = 0;
  // pull-up for all port B non-5 pins (0b11011111)
  PORTB = ~BIT5HI;
  PORTC = 0xff;
  PORTD = 0xff;
  while (1) {
    printf_P(PSTR("PINs B:%02X C:%02X D:%02X, Enter command: "), PINB, PINC,
             PIND);
    _delay_ms(1000);  // 1000 ms delay
    if (fgets(buf, sizeof buf - 1, stdin) == NULL) break;
    a1[0]='\0';
    a2[0]='\0';
    if (sscanf_P(buf, PSTR("%s %s"), a1, a2) > 0) {
      if (strcmp_P(a1, PSTR("ddra")) == 0) {
        printf_P(PSTR("Got 'ddra' command a2='%s'\n"), a2);
      } else {
        printf_P(PSTR("Got other command a1='%s' a2='%s'\n"), a1, a2);
      }
    } else {
      printf_P(PSTR("sscanf_P() failed\n"));
    }
  }
  printf_P(PSTR("Exit program ...\n "));
  return 0;
}
