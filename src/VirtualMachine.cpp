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

uint8_t VirtualMachine::readMemoryRelative8(int offset) {
    _byte_code->read8(_cpuState.instruction_ptr + offset);
}

void VirtualMachine::push8(uint8_t data) {
    _cpuState.stack.push(data);
}

uint8_t VirtualMachine::readStackAbsolute8(std::size_t address) {
    return _cpuState.stack.top();
}
