// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL
// Usable Baud Rate ... 9600 14400 19200 28800 38400 57600 2%
#define BAUD 19200
// Use with $ picocom -b 19200 /dev/ttyUSB0
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
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

int uart_putchar(char c, FILE *stream) {
  if (c == '\n') {
    uart_putchar('\r', stream);
  }
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}

#define SURE_LO 0
#define UNSURE 1
#define SURE_HI 2
#define BIT5HI 0b00100000

FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

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
  stdout = &uart_str;
  // For Data Direction Register of port B, set 5 pin as output for LED
  DDRB = BIT5HI;
  DDRC = 0;
  DDRD = 0;
  // pull-up for all port B non-5 pins (0b11011111)
  PORTB = ~BIT5HI;
  PORTC = 0xff;
  PORTD = 0xff;
  printf_P(PSTR("Hello world!\n"));
  while (1) {
    if ((previous == SURE_HI) & (check() == SURE_LO)) {
      // LED ON
      PORTB |= BIT5HI;
      printf_P(PSTR("PINB=%02X PINC=%02X PIND=%02X\n"), PINB, PINC, PIND);
      _delay_ms(3000);  // 3000 ms delay
      // LED OFF
      PORTB &= ~BIT5HI;
      previous = SURE_LO;
    } else if ((previous == SURE_LO) & (check() == SURE_HI)) {
      previous = SURE_HI;
    }
  }
}
