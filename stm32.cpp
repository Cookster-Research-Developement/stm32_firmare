void ota_start(uint32_t firmware_size, uint32_t expected_crc) {
    erase_flash(SLOT_B_ADDR, firmware_size);
}

void ota_write_chunk(uint32_t offset, uint8_t* data, uint32_t len) {
    flash_write(SLOT_B_ADDR + offset, data, len);
}

void ota_finish(uint32_t received_crc) {
    if (received_crc == expected_crc) {
        set_update_flag(expected_crc);
        system_reset();
    }
}