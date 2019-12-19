#ifndef SVM_BYTECODE_H
#define SVM_BYTECODE_H

#include "IByteCode.h"

class ByteCode : public IByteCode {
public:
    explicit ByteCode(const char *bc);

    std::optional<uint8_t> read8(size_t address) override;
    std::optional<uint32_t> read32(size_t address) override;

private:
    const char* _bc;
    uint32_t _bc_len;
};


#endif //SVM_BYTECODE_H
