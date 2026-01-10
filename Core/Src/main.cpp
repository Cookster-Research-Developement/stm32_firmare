#include "ota.h"

int main() {
    uint8_t data[16] = {0};

    ota_start(1024, 0x12345678);
    ota_write_chunk(0, data, sizeof(data));
    ota_finish(0x12345678);

    while (1);
}
