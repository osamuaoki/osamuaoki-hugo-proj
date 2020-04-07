#!/bin/sh -x
# This will erase everthing
sudo avrdude -p m328p -c avrisp2 -e || echo "EXIT_ERROR"

