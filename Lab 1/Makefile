#******************************************************************************
# Copyright (C) 2020 by Ashraf Abubaker - SEDC & University of Khartoum
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Ashraf Abubaker, SEDC and the University of Khartoum are not liable 
# for any misuse of this material. 
# 
# Created by Ashraf Abubaker for Microprocessor System Design Course 
# University of Khartoum - NOV 2018
# You can obtain this file from the Git Repository
# https://github.com/ashrafmalraheem/Mircoprocessor_Course
#*****************************************************************************

#------------------------------------------------------------------------------
# This is a make build file to generate different files (preprocessed,assembly,objects,.hex) 
# for Arduino Nano PLATFORM.
# Use: make [TARGET] 
#
# Build Targets:
#      <FILE>.o    - Builds <FILE>.o object file
#      <FILE>.d    - Builds <FILE>.d dependancy file
#      <FILE>.i    - Builds <FILE>.i preprocessed file
#      <FILE>.asm  - Builds <FILE>.asm assembly file
#      <FILE>.dump - Builds <FILE>.dump assembly file using the GNU AVR BIN utilities
#      main.hex    - output file and size for every output file using GNU AVR Bin utility
#      build       - Builds and links all source files
#      compile-all - build all files without linking
#      clean       - removes all generated files
#      upload      - upload the output file into Arduino platform
#      reupload    - clean, build and upload the output file into the platform
# Platform Overrides:
#      PLATFORM -  The platform for the output file to executre (atmega328p)
#
#------------------------------------------------------------------------------
include sources.mk
include specs.mk
# Architectures Specific Flags
LINKER_FILE =  -T ../msp432p401r.lds


# Compiler Flags and Defines
LD = avr-objcopy
LDFLAGS  = -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures
CFLAGS  := -O1 -Wall -std=gnu99 -DF_CPU=$(CLOCK_FREQ) -mmcu=$(MCU) 
CPPFLAGs = -E
ASFLAGS  = -S
AVRPATH  = "C:\MinGW\avr8-gnu-toolchain\bin/"
ifeq ($(MCU),atmega328p)
	CC = $(AVRPATH)avr-gcc
	SIZEUTIL = $(AVRPATH)avr-size
	AS       = $(AVRPATH)avr-as
# Add Bootloader and its Config file
	BOOTLOADER = $(AVRPATH)avrdude
	BOOT_CONFIG = avrdude.conf
endif

# Linux and Windows CMD commands
ifeq ($(OS),LINUX)
	DELETE = rm -f
	LIST_DIR = ls -la
else
	DELETE = del
	LIST_DIR = dir
endif

ifndef COM
$(error COM is not set)
endif

# Recipes
OBJS  := $(SOURCES:.c=.o)
%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES) -B$(LINK_INC)  
	$(SIZEUTIL) -Btd $@ 
ELFS  := $(OBJS:.o=.elf)
$(TARGET).elf : compile-all
	$(CC) -o $@ $(OBJS) -Wl,-Map="$(TARGET).map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=$(MCU) -B$(LINK_INC) 
PRES  := $(SOURCES:.c=.i)
%.i : %.c
	$(CC) -E $(INCLUDES) $(CFLAGS) $< -o $@ 
ASMBDUMP := $(SOURCES:.c=.asm)
%.asm : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@
DEP   := $(SOURCES:.c=.d)
%.d : %.c
	$(CC) -MM $(INCLUDES) $(CFLAGS) -MD -MP $< -o $@ 

# PHONY Directives
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -B$(LINK_INC)

.PHONY: build 
build: compile-all $(TARGET).hex
$(TARGET).hex: $(TARGET).elf $(TARGET).asm
	$(AVRPATH)$(LD) $(LDFLAGS) "$(TARGET).elf" "$(TARGET).hex"
	$(SIZEUTIL) -Btd $@ $(OBJS)

.PHONY: clean
clean: 
	$(DELETE) *.dep *.d *.i *.o *.asm *.out *.hex *.elf *.map *.s
	$(LIST_DIR)

.PHONY: upload
upload:
	$(BOOTLOADER) -C$(BOOT_CONFIG) -v -p$(MCU) -c$(PLATFORM) -P$(COM) -b$(BAUD_RATE) -D -Uflash\:w\:"$(TARGET).hex"\:i

.PHONY: all
all: build upload