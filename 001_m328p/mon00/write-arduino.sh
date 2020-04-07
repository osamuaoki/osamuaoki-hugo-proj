#!/bin/sh
sudo avrdude -p m328p -c arduino -P /dev/ttyUSB0 -U flash:w:main.hex || echo "EXIT_ERROR"

