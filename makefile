
##########------------------------------------------------------##########
##########              Project-specific Details                ##########
##########    Check these every time you start a new project    ##########
##########------------------------------------------------------##########

include makefile.local

MCU = atmega2560
F_CPU = 8000000
BAUD = 115200
## Also try BAUD = 19200 or 38400 if you're feeling lucky.

## This is where your main() routine lives 
MAIN = FL2.cpp
OBJDIR = ./objs

## If you've split your program into multiple .c / .h files, 
## include the additional source (in same directory) here 
LOCAL_INCLUDE_DIR = ./
LOCAL_SOURCE = Altimeter.cpp ConsoleLogger.cpp ConsoleSerialPort.cpp LCD.cpp Logger.cpp PanelLogger.cpp SerialPort.cpp
LOCAL_OBJECTS = Altimeter.o ConsoleLogger.o ConsoleSerialPort.o LCD.o Logger.o PanelLogger.o SerialPort.o
# LOCAL_SOURCE += GPS.cpp
# LOCAL_SOURCE += GpsSerialPort.cpp
# LOCAL_SOURCE += Gyro.cpp

# This should now be defined in makefile.local
## Where do the arduino files live
# ARDUINO_LIBS_ROOT = /Users/chris/development/arduino/Arduino

## Here you can link to one more directory (and multiple .c files)
EXTRA_SOURCE_DIR = -I$(ARDUINO_LIBS_ROOT)/hardware/arduino/cores/arduino/ 
EXTRA_SOURCE_DIR += -I$(ARDUINO_LIBS_ROOT)/hardware/arduino/variants/mega/
EXTRA_SOURCE_DIR += -I$(ARDUINO_LIBS_ROOT)/libraries/SoftwareSerial/ 
EXTRA_SOURCE_DIR += -I$(ARDUINO_LIBS_ROOT)/libraries/Wire/ 
EXTRA_SOURCE_DIR += -I$(ARDUINO_LIBS_ROOT)/libraries/LiquidCrystal/ 
EXTRA_SOURCE_DIR += -Ilib/Adafruit_BMP085/ 
# EXTRA_SOURCE_DIR += -Ilib/Adafruit_GPS/

EXTRA_SOURCE_FILES = /hardware/arduino/cores/arduino/wiring.c
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/wiring_analog.c
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/wiring_digital.c
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/wiring_pulse.c
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/wiring_shift.c
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/WString.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/WMath.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/Stream.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/HardwareSerial.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/Print.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/Tone.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/IPAddress.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/USBCore.cpp
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/WInterrupts.c
EXTRA_SOURCE_FILES += /hardware/arduino/cores/arduino/new.cpp
ARDUINO_CORE_LIBS = $(addprefix $(ARDUINO_LIBS_ROOT)/, $(EXTRA_SOURCE_FILES))

##########------------------------------------------------------##########
##########                 Programmer Defaults                  ##########
##########          Set up once, then forget about it           ##########
##########        (Can override.  See bottom of file.)          ##########
##########------------------------------------------------------##########

PROGRAMMER_TYPE = wiring
# extra arguments to avrdude: baud rate, chip type, -F flag, etc.
PROGRAMMER_ARGS = -v -v -v -v -v -b$(BAUD) -P/dev/tty.usbmodem1441

##########------------------------------------------------------##########
##########                   Makefile Magic!                    ##########
##########         Summary:                                     ##########
##########             We want a .hex file                      ##########
##########        Compile source files into .elf                ##########
##########        Convert .elf file into .hex                   ##########
##########        You shouldn't need to edit below.             ##########
##########------------------------------------------------------##########

## Defined programs / locations
CC = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude

## Compilation options, type if you're curious.
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=$(BAUD) -Os -I. $(EXTRA_SOURCE_DIR)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
CFLAGS += -Wall 
CFLAGS += -g -ggdb
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections -Wl,--relax
## CFLAGS += -std=gnu99
## CFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
## CFLAGS += -Wl,-u,vfprintf -lprintf_min      ## for smaller printf

## Lump target and extra source files together
TARGET = $(strip $(basename $(MAIN)))
SRC = $(TARGET).cpp
SRC += $(LOCAL_SOURCE) 
EXTRA_SOURCE = $(EXTRA_SOURCE_FILES)
EXTRA_SOURCE += $(ARDUINO_CORE_LIBS)

## List of all header files
HEADERS = $(SRC:.cpp=.h) 

## For every .c file, compile an .o object file
OBJ = $(SRC:.cpp=.o) 

OBJECTS = $(addprefix $(OBJDIR)/, wiring.o wiring_analog.o wiring_digital.o wiring_pulse.o wiring_shift.o WString.o WMath.o Stream.o HardwareSerial.o Print.o Tone.o IPAddress.o USBCore.o WInterrupts.o new.o Adafruit_BMP085.o Adafruit_GPS.o Adafruit_L3GD20.o)

## Generic Makefile targets.  (Only .hex file is necessary)
all: FL2.hex

FL2.hex: FL2.elf
	@echo
	@echo "FL2.hex: building FL2.hex:" 
	$(OBJCOPY) -R .eeprom -O ihex $< $@

FL2.elf: $(OBJ) | $(OBJECTS) 
	@echo
	@echo "FL2.elf: building FL2.elf:" 

$(OBJ): $(SRC)
	@echo
	@echo "LOCAL_OBJECTS: building local objects:" 
	$(CC) $(CFLAGS) $(EXTRA_SOURCE_DIR) $(LOCAL_INCLUDE_DIR) -c $< --output $@ 

FL2.eeprom: FL2.elf
	@echo
	@echo "FL2.eeprom: building FL2.eeprom:" 
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ 

$(OBJECTS): $(ARDUINO_CORE_LIBS) | $(OBJDIR)
	@echo
	@echo "Building 3rd part objects:" 
	$(CC) $(CFLAGS) $(EXTRA_SOURCE_DIR) -c $< --output $@
	@echo "3rd party object compilation complete.\n" 
	
$(OBJDIR):
	@echo
	@echo "creating 3rd party object directory:" 
	mkdir -p $(OBJDIR)

debug:
	@echo
	@echo "Source files: \n\t"   $(SRC)
	@echo
	@echo "MCU, F_CPU, BAUD: "  $(MCU), $(F_CPU), $(BAUD)
	@echo	
	@echo "Build command: \n\t" $(CC) $(CFLAGS) $(SRC)
	@echo 
	@echo "Third party objects: \n\t" $(OBJECTS)
	@echo 
	@echo "Third party includes: \n\t" $(EXTRA_SOURCE_DIR)
	@echo 
	@echo "Third party sources: \n\t" $(EXTRA_SOURCE)

# Optionally create listing file from .elf
# This creates approximate assembly-language equivalent of your code.
# Useful for debugging time-sensitive bits, 
# or making sure the compiler does what you want.
disassemble: FL2.lst

disasm: disassemble

eeprom: FL2.eeprom

FL2.lst: FL2.elf
	$(OBJDUMP) -S $< > $@

# Optionally show how big the resulting program is 
size:  FL2.elf
	$(AVRSIZE) -C --mcu=$(MCU) FL2.elf

clean:
	rm -rf $(TARGET).elf $(TARGET).hex $(TARGET).obj \
	$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
	$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
	$(TARGET).eeprom $(OBJDIR)

squeaky_clean: clean
	rm -f *.elf *.hex *.obj *.o *.out *.d *.eep *.lst *.lss *.sym *.map *~

##########------------------------------------------------------##########
##########              Programmer-specific details             ##########
##########           Flashing code to AVR using avrdude         ##########
##########------------------------------------------------------##########

flash: $(TARGET).hex 
	$(AVRDUDE) -c$(PROGRAMMER_TYPE) -p$(MCU) $(PROGRAMMER_ARGS) -Uflash:w:$<

## An alias
program: flash

flash_eeprom: $(TARGET).eeprom
	$(AVRDUDE) -c$(PROGRAMMER_TYPE) -p$(MCU) $(PROGRAMMER_ARGS) -Ueeprom:w:$<

avrdude_terminal:
	$(AVRDUDE) -c$(PROGRAMMER_TYPE) -p$(MCU) $(PROGRAMMER_ARGS) -nt

## If you've got multiple programmers that you use, 
## you can define them here so that it's easy to switch.
## To invoke, use something like `make flash_arduinoISP`
flash_usbtiny: PROGRAMMER_TYPE = usbtiny
flash_usbtiny: PROGRAMMER_ARGS =  # USBTiny works with no further arguments
flash_usbtiny: flash

flash_usbasp: PROGRAMMER_TYPE = usbasp
flash_usbasp: PROGRAMMER_ARGS =  # USBasp works with no further arguments
flash_usbasp: flash

flash_arduinoISP: PROGRAMMER_TYPE = avrisp
flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P /dev/ttyACM0 
## (for windows) flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P com5
flash_arduinoISP: flash

flash_109: PROGRAMMER_TYPE = avr109
flash_109: PROGRAMMER_ARGS = -b 9600 -P /dev/ttyUSB0
flash_109: flash

##########------------------------------------------------------##########
##########       Fuse settings and suitable defaults            ##########
##########------------------------------------------------------##########

## Mega 48, 88, 168, 328 default values
LFUSE = 0x62
HFUSE = 0xdf
EFUSE = 0x00

## Generic 
FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m 

fuses: 
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) \
	           $(PROGRAMMER_ARGS) $(FUSE_STRING)
show_fuses:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nv	

## Called with no extra definitions, sets to defaults
set_default_fuses:  FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m 
set_default_fuses:  fuses

## Set the fuse byte for full-speed mode
## Note: can also be set in firmware for modern chips
set_fast_fuse: LFUSE = 0xE2
set_fast_fuse: FUSE_STRING = -U lfuse:w:$(LFUSE):m 
set_fast_fuse: fuses

## Set the EESAVE fuse byte to preserve EEPROM across flashes
set_eeprom_save_fuse: HFUSE = 0xD7
set_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
set_eeprom_save_fuse: fuses

## Clear the EESAVE fuse byte
clear_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
clear_eeprom_save_fuse: fuses
