#ifndef OTA_H
#define OTA_H

#include <stdint.h>

void ota_start(uint32_t firmware_size, uint32_t expected_crc);
void ota_write_chunk(uint32_t offset, uint8_t* data, uint32_t len);
void ota_finish(uint32_t received_crc);

#endif
