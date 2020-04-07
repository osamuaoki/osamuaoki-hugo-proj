// vim: ft=c sts=2 sw=2 et si ai:
//

#include <avr/io.h>
/* Read UART value and convert it to ASCII*/
static char read_and_convert(void) { return (PINB + 0x48); }
/* Write to UART*/
int main(void) {
  while (1) {
    UDR0 = read_and_convert();
  }
}
