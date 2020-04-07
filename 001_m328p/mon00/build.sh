#!/bin/sh
avr-gcc -mmcu=atmega328p -Wall -Os -o main.elf main.c || echo "EXIT_ERROR"
avr-objcopy -j .text -j .data -O ihex main.elf main.hex || echo "EXIT_ERROR"

