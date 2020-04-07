#!/bin/sh
avr-gcc -mmcu=atmega328p -Wall -Os -o hello.elf hello.c || echo "EXIT_ERROR"
avr-objcopy -j .text -j .data -O ihex hello.elf hello.hex || echo "EXIT_ERROR"

