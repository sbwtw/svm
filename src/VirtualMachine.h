#ifndef SVM_VIRTUALMACHINE_H
#define SVM_VIRTUALMACHINE_H

#include <stack>
#include <cstdint>

#include "IVirtualMachine.h"

class VirtualMachine : public IVirtualMachine {
public:
    void run(IByteCode &bc) override;

    uint8_t readMemoryRelative8(std::size_t address) override;

protected:
    void exePlus8() override;
    void stop() override;
    void push8(uint8_t data) override;

private:
    IByteCode *_byte_code;
    bool _running = true;
    CpuState _cpuState;
};


#endif //SVM_VIRTUALMACHINE_H
