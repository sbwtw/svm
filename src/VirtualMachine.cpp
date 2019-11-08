#include "VirtualMachine.h"
#include "IByteCode.h"

#include <iostream>

using namespace std;

void VirtualMachine::run(IByteCode &bc) {
    _byte_code = &bc;

    while (_running)
    {
        auto instruction = bc.instruction(_cpuState.instruction_ptr);

        cout << "Execute " << hex << instruction->instructionAddress() << endl;

        _cpuState.instruction_ptr += instruction->execute(*this, bc);
    }

    cout << "Stack: ";
    while (!_cpuState.stack.empty())
    {
        cout << hex << _cpuState.stack.top() << ", " << endl;
        _cpuState.stack.pop();
    }
}

void VirtualMachine::exePlus8() {
    uint8_t a = _cpuState.stack.top();
    _cpuState.stack.pop();
    uint8_t b = _cpuState.stack.top();
    _cpuState.stack.pop();

    _cpuState.stack.push(a + b);
}

//void VirtualMachine::decode(Operand op, IByteCode &bc) {
//    switch (Operand)
//    {
//    }
//}

void VirtualMachine::stop() {
    _running = false;
}

uint8_t VirtualMachine::readMemoryRelative8(std::size_t address) {
    _byte_code->read8(_cpuState.instruction_ptr + address);
}

void VirtualMachine::push8(uint8_t data) {
    _cpuState.stack.push(data);
}
