#include <cstring>

#include "ByteCode.h"

using namespace std;

optional<uint8_t> ByteCode::read8(size_t address) {
    if (address < _bc_len)
        return _bc[address];
    return {};
}

optional<uint32_t> ByteCode::read32(size_t address) {
    return {};
}

ByteCode::ByteCode(const char *bc)
    : _bc(bc) {
    _bc_len = strlen(bc);
}
