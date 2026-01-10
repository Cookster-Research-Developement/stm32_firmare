CC = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy

TARGET = firmware
BUILD_DIR = build

INCLUDES = -ICore/Inc

CFLAGS = -mcpu=cortex-m4 -mthumb -O2 \
         -ffunction-sections -fdata-sections \
         -fno-exceptions -fno-rtti -fno-unwind-tables -fno-asynchronous-unwind-tables \
         -nostdlib \
         -ICore/Inc

LDFLAGS = -T linker.ld -Wl,--gc-sections -nostartfiles

SRC = Core/Src/main.cpp \
      Core/Src/ota.cpp \
      Core/Src/version.cpp


all: $(BUILD_DIR)/$(TARGET).elf bin

$(BUILD_DIR)/$(TARGET).elf: $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

bin:
	mkdir -p output
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(TARGET).elf output/$(TARGET).bin

clean:
	rm -rf build output
