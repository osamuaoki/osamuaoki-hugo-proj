// vim: ft=c sts=2 sw=2 et si ai:
//
// Arduino nano board is 16 MHz
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SURE_LO 0
#define UNSURE 1
#define SURE_HI 2
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

#define BIT5HI 0b00100000
int main(void) {
  int previous = SURE_HI;  // pull-uped
  // For Data Direction Register of port B, set 5 pin as output for LED
  DDRB = BIT5HI;
  // pull-up for all port B non-5 pins (0b11011111)
  PORTB = ~BIT5HI;
  while (1) {
    if ((previous == SURE_HI) & (check() == SURE_LO)) {
      // LED ON
      PORTB |= BIT5HI;
      _delay_ms(3000);  // 3000 ms delay
      // LED OFF
      PORTB &= ~BIT5HI;
      previous = SURE_LO;
    } else if ((previous == SURE_LO) & (check() == SURE_HI)) {
      previous = SURE_HI;
    }
  }
}
