#!/bin/sh
avr-gcc -mmcu=atmega328p -Wall -Os -o blink.elf blink.c || echo "EXIT_ERROR"
avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex || echo "EXIT_ERROR"

