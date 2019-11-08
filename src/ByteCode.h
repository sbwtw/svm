#ifndef SVM_BYTECODE_H
#define SVM_BYTECODE_H

#include "IByteCode.h"

class ByteCode : public IByteCode {
public:
    explicit ByteCode(const char *bc);

    uint8_t read8(size_t address) override;
    uint32_t read32(size_t address) override;

private:
    const char* _bc;
};


#endif //SVM_BYTECODE_H
