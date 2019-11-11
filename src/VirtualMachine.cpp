#include "VirtualMachine.h"
#include "IByteCode.h"

#include <iostream>
#include <cassert>

using namespace std;

void VirtualMachine::run(IByteCode &bc) {
    _byte_code = &bc;

    while (_running)
    {
        auto instruction = bc.instruction(_cpuState.instruction_ptr);

        _cpuState.instruction_ptr += instruction->execute(*this);
    }
}

void VirtualMachine::stop() {
    _running = false;
}

uint8_t VirtualMachine::readMemoryRelative8(int offset) {
    return _byte_code->read8(_cpuState.instruction_ptr + offset);
}

void VirtualMachine::push8(uint8_t data) {
    _cpuState.stack.push_front(data);
}

uint8_t VirtualMachine::readStack8(std::size_t address) {
    assert(address < _cpuState.stack.size());

    auto it = next(_cpuState.stack.cbegin(), address);

    return *it;
}

uint8_t VirtualMachine::pop8() {
    auto data = _cpuState.stack.front();
    _cpuState.stack.pop_front();

    return data;
}

CpuState &VirtualMachine::cpuState() {
    return _cpuState;
}
