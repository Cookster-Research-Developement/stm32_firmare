#include "ota.h" //sloting

#define SLOT_B_ADDR 0x08020000

static uint32_t expected_crc_global;

void erase_flash(uint32_t addr, uint32_t size) {
    // dummy for build test
}

void flash_write(uint32_t addr, uint8_t* data, uint32_t len) {
    // dummy for build test
}

void set_update_flag(uint32_t crc) {
    // dummy
}

void system_reset() {
    while (1);
}

void ota_start(uint32_t firmware_size, uint32_t expected_crc) {
    expected_crc_global = expected_crc;
    erase_flash(SLOT_B_ADDR, firmware_size);
}

void ota_write_chunk(uint32_t offset, uint8_t* data, uint32_t len) {
    flash_write(SLOT_B_ADDR + offset, data, len);
}

void ota_finish(uint32_t received_crc) {
    if (received_crc == expected_crc_global) {
        set_update_flag(received_crc);
        system_reset();
    }
}
