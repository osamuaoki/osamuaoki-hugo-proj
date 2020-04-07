// vim: ft=c sts=2 sw=2 et si ai:
//
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  CLKPR = 0x80;
  CLKPR = 0; // set cpu prescale to 1 (disable CKDIV8)
  DDRD = (0xff);
  while (1) {
    PORTD = (0xff);
   _delay_ms(100);  // 0.1 s delay *
    PORTD = 0;
    _delay_ms(1000);  // 1.0 s delay
  }
}
