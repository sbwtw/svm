#ifndef SVM_DISASSEMBLER_H
#define SVM_DISASSEMBLER_H

#include "IByteCode.h"

#include <ostream>

class IDisassembler {
public:
    virtual ~IDisassembler() = default;

    virtual uint8_t read(int offset) = 0;
    virtual void disassembly(std::ostream &out, IByteCode &bc) = 0;

public:
    uint64_t offset = 0;
};

class Disassembler : public IDisassembler {
public:
    explicit Disassembler(const char * bc);

    uint8_t read(int offset) override;
    void disassembly(std::ostream &out, IByteCode &bc) override;

private:
    const char *byte_code;
};


#endif //SVM_DISASSEMBLER_H
