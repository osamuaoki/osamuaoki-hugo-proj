# AVR USB Chip initialization

This contain resources to initialize teensy2 and teensy2++ comptible boards
with free bootloaders.

For smaller memory ATmega32u4, I use nanoBoot (512B).

For larger AT90USB1286, I use one of LUFA boot loaders (4K). (The first choice is HID)

The `./setup-teensy` will downloads binaries.

avrmonを使う際は

 $ picocom /dev/ttyACM


Osamu

