#!/bin/sh -x
echo === HEX berkeley ===
avr-size --target=ihex main.hex
echo === ELF avr ===
avr-size --mcu=atmega328p --format=avr main.elf
echo === === ===
