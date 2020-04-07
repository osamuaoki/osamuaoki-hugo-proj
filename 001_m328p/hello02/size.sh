#!/bin/sh
echo === HEX berkeley ===
avr-size --target=ihex hello.hex
echo === ELF avr ===
avr-size --mcu=atmega328p --format=avr hello.elf
echo === === ===
