// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL

#include <avr/io.h>

int main(void) {
  // For Data Direction Register of port B, set 5 pin as output for LED
  DDRB = 0b00100000;
  // pull-up for all port B non-5 pins (0b11011111)
  PORTB = ~0b00100000;
  while (1) {
    // Check if any one of low 5 bits 01234 of PORTB is grounded
    if ((PINB & 0x1f) == 0x1f) {
      // not grounded -> LED ON
      PORTB |= 0b00100000;
    } else {
      // grounded -> LED OFF
      PORTB &= ~0b00100000;
    }
  }
}
