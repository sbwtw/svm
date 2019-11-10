#ifndef SVM_VIRTUALMACHINE_H
#define SVM_VIRTUALMACHINE_H

#include <stack>
#include <cstdint>

#include "IVirtualMachine.h"

class VirtualMachine : public IVirtualMachine {
public:
    void run(IByteCode &bc) override;

    uint8_t readMemoryRelative8(int offset) override;
    uint8_t readStack8(std::size_t address) override;

protected:
    void stop() override;
    void push8(uint8_t data) override;
    uint8_t pop8() override;

private:
    IByteCode *_byte_code;
    bool _running = true;
    CpuState _cpuState;
};


#endif //SVM_VIRTUALMACHINE_H
