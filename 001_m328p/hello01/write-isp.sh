#!/bin/sh
sudo avrdude -p m328p -c avrisp2 -U flash:w:hello.hex || echo "EXIT_ERROR"

