#include "VirtualMachine.h"
#include "IByteCode.h"

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

void VirtualMachine::run(IByteCode &bc) {
    _byte_code = &bc;

    while (_running)
    {
        auto instruction = bc.instruction(_cpuState.instruction_ptr);

        // dump stack
        cout << "Stack: ";
        for (auto v : _cpuState.stack)
        {
            cout << setw(2) << setfill('0') << hex << (short)v << ' ';
        }
        cout << endl;
    }
}

void VirtualMachine::stop() {
    _running = false;
}

uint8_t VirtualMachine::readMemoryRelative8(int offset) {
    return _byte_code->read8(_cpuState.instruction_ptr + offset).value();
}

void VirtualMachine::push8(uint8_t data) {
    _cpuState.stack.push_back(data);
}

uint8_t VirtualMachine::readStack8(std::size_t address) {
    assert(address < _cpuState.stack.size());

    auto it = next(_cpuState.stack.cbegin(), address);

    return *it;
}

uint8_t VirtualMachine::pop8() {
    auto data = _cpuState.stack.back();
    _cpuState.stack.pop_back();

    return data;
}

CpuState &VirtualMachine::cpuState() {
    return _cpuState;
}
