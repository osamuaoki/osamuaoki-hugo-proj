// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL
// Usable Baud Rate ... 9600 14400 19200 28800 38400 57600 2%
#define BAUD 19200
// Use with $ picocom -b 19200 /dev/ttyUSB0
#include <avr/io.h>
#include <avr/pgmspace.h>
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
  /* transmitter enable */
  UCSR0B = _BV(TXEN0);
}

int uart_putchar(char c) {
  if (c == '\n') {
    uart_putchar('\r');
  }
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}

int uart_puts_P(PGM_P s) {
  char c;
  while (1) {
    c = pgm_read_byte(s++);
    if (c == '\0') break;
    uart_putchar(c);
  }
  return 0;
}

int uart_put_byte(char c, char x0, char x1) {
  for (int i = 0; i < 8; i++) {
    uart_putchar((c & 0x80) ? x0 : x1);
    c = c << 1;
  }
  return 0;
}

int uart_put_byte_10(char c) { return uart_put_byte(c, '1', '0'); }

int uart_put_byte_OI(char c) { return uart_put_byte(c, 'O', 'I'); }

int uart_put_byte_MK(char c) { return uart_put_byte(c, '*', '_'); }

#define SURE_LO 0
#define UNSURE 1
#define SURE_HI 2
#define BIT5HI 0b00100000

int check(void) {
  // Check if any one of low 5 bits 01234 of PORTB is grounded
  if ((PINB & 0x1f) != 0x1f) {
    _delay_ms(50);  // 50 ms delay
    if ((PINB & 0x1f) != 0x1f) {
      return SURE_LO;
    }
  }
  // Check if all low 5 bits 01234 of PORTB are not grounded
  else if ((PINB & 0x1f) == 0x1f) {
    _delay_ms(50);  // 50 ms delay
    if ((PINB & 0x1f) == 0x1f) {
      return SURE_HI;
    }
  }
  return UNSURE;
}

int main(void) {
  int previous = SURE_HI;  // pull-uped
  uart_init();
  // For Data Direction Register of port B, set 5 pin as output for LED
  DDRB = BIT5HI;
  DDRC = 0;
  DDRD = 0;
  // pull-up for all port B non-5 pins (0b11011111)
  PORTB = ~BIT5HI;
  PORTC = 0xff;
  PORTD = 0xff;
  uart_puts_P(PSTR("Hello world!\n"));
  while (1) {
    if ((previous == SURE_HI) & (check() == SURE_LO)) {
      // LED ON
      PORTB |= BIT5HI;
      uart_puts_P(PSTR("DDRB ="));
      uart_put_byte_OI(DDRB);
      uart_puts_P(PSTR(" DDRC ="));
      uart_put_byte_OI(DDRC);
      uart_puts_P(PSTR(" DDRD ="));
      uart_put_byte_OI(DDRD);
      uart_puts_P(PSTR("\n"));
      uart_puts_P(PSTR("PORTB="));
      uart_put_byte_MK(PORTB);
      uart_puts_P(PSTR(" PORTC="));
      uart_put_byte_MK(PORTC);
      uart_puts_P(PSTR(" PORTD="));
      uart_put_byte_MK(PORTD);
      uart_puts_P(PSTR("\n"));
      uart_puts_P(PSTR("PINB ="));
      uart_put_byte_10(PINB);
      uart_puts_P(PSTR(" PINC ="));
      uart_put_byte_10(PINC);
      uart_puts_P(PSTR(" PIND ="));
      uart_put_byte_10(PIND);
      uart_puts_P(PSTR("\n.....................\n"));
      _delay_ms(3000);  // 3000 ms delay
      // LED OFF
      PORTB &= ~BIT5HI;
      previous = SURE_LO;
    } else if ((previous == SURE_LO) & (check() == SURE_HI)) {
      previous = SURE_HI;
    }
  }
}
