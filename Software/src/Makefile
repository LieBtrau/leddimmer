# Parameters for compiling

ARDUINO_DIR     = /usr/share/arduino
TARGET          = output
ARDUINO_LIBS    =
ARDUINO_VAR_PATH  = /usr/avr/include
#arduino tiny project downloaded from: https://code.google.com/p/arduino-tiny/downloads/detail?name=arduino-tiny-0100-0018.zip
ARDUINO_CORE_PATH = /home/ctack/sketchbook/hardware/tiny/cores/tiny
ARDUINO_PORT = usb

# Avrdude code for programming
AVRDUDE                 = /usr/bin/avrdude
BOARD_TAG               = attiny25at1
ALTERNATE_CORE          = tiny
ISP_PROG	        = avrisp2
ISP_PORT                = usb
# Arduino makefile

include $(ARDUINO_DIR)/Arduino.mk

# build project: make all
# program AVR: make ispload
# clean project: clean all
