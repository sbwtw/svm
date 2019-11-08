#ifndef SVM_BYTECODE_H
#define SVM_BYTECODE_H

#include "IByteCode.h"

class ByteCode : public IByteCode {
public:
    uint8_t read8(size_t address) override;
    uint32_t read32(size_t address) override;

private:
    char *bc = "\x01\x01\x01\x02\x02\x00";
};


#endif //SVM_BYTECODE_H
