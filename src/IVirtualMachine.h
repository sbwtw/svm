#ifndef SVM_IVIRTUALMACHINE_H
#define SVM_IVIRTUALMACHINE_H

#include <list>
#include <cstdint>

struct CpuState {
    std::size_t instruction_ptr = 0;
    std::list<uint8_t> stack;

    bool zero_flag: 1;
};

class IByteCode;
class IVirtualMachine {
public:
    explicit IVirtualMachine() = default;
    virtual ~IVirtualMachine() = default;

public:
    virtual void run(IByteCode &bc) = 0;
    virtual void stop() = 0;
    virtual void push8(uint8_t data) = 0;
    virtual uint8_t pop8() = 0;
    virtual uint8_t readMemoryRelative8(int offset) = 0;
    virtual uint8_t readStack8(std::size_t address) = 0;
    virtual CpuState& cpuState() = 0;
};


#endif //SVM_IVIRTUALMACHINE_H
