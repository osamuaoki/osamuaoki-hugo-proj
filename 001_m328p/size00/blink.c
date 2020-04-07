// vim: ft=c sts=2 sw=2 et si ai:
//

#include <avr/io.h>
/* A macro to read UART value and convert it to ASCII*/
#define read_and_convert() (PINB + 0x48)
/* Write to UART*/
int main(void) { UDR0 = read_and_convert(); }
