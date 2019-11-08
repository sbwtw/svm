#ifndef SVM_IVIRTUALMACHINE_H
#define SVM_IVIRTUALMACHINE_H

#include <stack>
#include <cstdint>

struct CpuState {
    std::size_t instruction_ptr = 0;
    std::stack<uint8_t> stack;
};

class IByteCode;
class IVirtualMachine {
public:
    explicit IVirtualMachine() = default;
    virtual ~IVirtualMachine() = default;

public:
    virtual void run(IByteCode &bc) = 0;
    virtual void exePlus8() = 0;
    virtual void stop() = 0;
    virtual void push8(uint8_t data) = 0;
    virtual uint8_t readMemoryRelative8(std::size_t address) = 0;
};


#endif //SVM_IVIRTUALMACHINE_H
