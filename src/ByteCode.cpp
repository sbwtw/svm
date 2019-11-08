#include "ByteCode.h"

uint8_t ByteCode::read8(size_t address) {
    return _bc[address];
}

uint32_t ByteCode::read32(size_t address) {
    return 0;
}

ByteCode::ByteCode(const char *bc)
    : _bc(bc) {

}
