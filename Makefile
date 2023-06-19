CC=g++
INCLUDE_DIR := $(shell pwd)/include
BIN_DIR := $(shell pwd)/bin
OBJ_DIR := $(shell pwd)/obj
SRC := $(shell pwd)/src
CFLAGS := -g -Wall
OBJECTS = objdir compilesrc


ARDUINO_DIR = /usr/share/arduino
ARDMK_DIR = /usr/share/arduino
AVRDUDE_CONF = /etc/avrdude.conf
ARDUINO_CORE_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/cores/arduino
ARDUINO_PLATFORM_LIB_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/libraries
BOARDS_TXT = /usr/share/arduino/hardware/archlinux-arduino/avr/boards.txt
ARDUINO_VAR_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/variants
BOOTLOADER_PARENT = /usr/share/arduino/hardware/archlinux-arduino/avr/bootloaders
BOARD_TAG    = uno
CPPFLAGS += -I/usr/share/arduino/hardware/archlinux-arduino/avr/libraries/stlport

all: $(OBJECTS)
	$(CC) $(OBJ_DIR)/*.o -o $(BIN_DIR)/main 
	rm -r $(OBJ_DIR)

objdir:
	mkdir -p $(OBJ_DIR)

compilesrc:
	$(CC) -c $(SRC)/*.cpp $(CFLAGS) -I$(INCLUDE_DIR) 
	mv $(shell pwd)/*.o $(OBJ_DIR)


include /usr/share/arduino/Arduino.mk