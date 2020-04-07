#!/bin/sh -x
# Thus needs ISP
# This will erase everthing and furce to set fuse
# Non-exisrung lock fuse bit 6 and 7 are read as 1: set to --> 0xFF
sudo avrdude -p m328p -c avrisp2 -F -e -U lock:w:0xFF:m \
	-U efuse:w:0xfd:m -U hfuse:w:0xde:m -U lfuse:w:0xff:m || echo "EXIT_ERROR"
# load optiboot for atmega328
# symlinked from /usr/share/arduino/hardware/arduino/bootloaders/optiboot
# This is assuming you are on Debian with Arduino
sudo avrdude -p m328p -c avrisp2 -U flash:w:optiboot_atmega328.hex || echo "EXIT_ERROR"

