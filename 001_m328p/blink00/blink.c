// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // For Data Direction Register of port B, set the 5th bit (OR)
  DDRB |= _BV(DDB5);
  while (1) {
    // For Port B, toggle the 5th bit (XOR)
    PORTB ^= _BV(PORTB5);
    _delay_ms(500);  // 500 ms delay
  }
}
