#!/bin/sh
echo === HEX berkeley ===
avr-size --target=ihex blink.hex
echo === ELF avr ===
avr-size --mcu=atmega328p --format=avr blink.elf
echo === HEX sysv  ===
avr-size --target=ihex --format=sysv blink.hex
echo === ELF sysv  ===
avr-size --mcu=atmega328p --format=sysv --target=ihex blink.hex
echo === ELF berkeley  ===
avr-size --mcu=atmega328p --format=berkeley --target=ihex blink.hex
echo === === ===
