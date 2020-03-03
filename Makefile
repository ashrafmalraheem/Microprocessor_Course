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
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map\
	  -O0
CFLAGS  := -O1 -Wall -std=gnu99 -DF_CPU=$(CLOCK_FREQ) -mmcu=$(MCU) 
CPPFLAGs = -E
ASFLAGS  = -S
ifeq ($(MCU),atmega328p)
	CC = avr-gcc
	SIZEUTIL = avr-size
# Add Bootloader and its Config file
	BOOTLOADER = avrdude
	BOOT_CONFIG = avrdude.conf
endif
OBJS  := $(SOURCES:.c=.o)
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -B$(LINK_INC) -MD -MP -MF "$(TARGET).d" -MT"$(TARGET).d" -o $@
	$(SIZEUTIL) -Btd $@ 
ELFS  := $(OBJS:.o=.elf)
$(TARGET).elf : $(TARGET).o
	$(CC) -o $@ $< -Wl,-Map="$(TARGET).map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=$(MCU) -B$(LINK_INC) 
PRES  := $(SOURCES:.c=.i)
%.i : %.c
	$(CC) -E $(INCLUDES) $(CLFAGS) $< -o $@
ASMBDUMP := $(OBJS:.o=.asm)
%.asm : %.o
	$(AS) --disassemble -S $< > $@
DEP   := $(SOURCES:.c=.d)
%.d : %.c
	$(CC) -MM $(INCLUDES) $(CLFAGS) $< -o $@ 

.PHONY: compile-all 
compile-all: $(OBJS) 

.PHONY: build 
build: $(TARGET).hex
$(TARGET).hex: $(TARGET).o $(TARGET).elf 
	avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "$(TARGET).elf" "$(TARGET).hex"
	$(SIZEUTIL) -Btd $@ $(OBJS)

.PHONY: clean
clean: 
	rm -f *.dep *.d *.i *.o *.asm *.out *.hex
	ls -la

.PHONY: upload
upload:
	$(BOOTLOADER) -C$(BOOT_CONFIG) -v -p$(MCU) -c$(PLATFORM) -P$(COM) -b$(BAUD_RATE) -D -Uflash\:w\:"$(TARGET).hex"\:i

.PHONY: all
all: clean build upload