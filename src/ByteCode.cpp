#include "ByteCode.h"

uint8_t ByteCode::read8(size_t address) {
    return bc[address];
}

uint32_t ByteCode::read32(size_t address) {
    return 0;
}
