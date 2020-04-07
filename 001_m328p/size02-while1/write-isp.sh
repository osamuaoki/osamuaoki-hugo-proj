#!/bin/sh
sudo avrdude -p m328p -c avrisp2 -U flash:w:blink.hex || echo "EXIT_ERROR"

