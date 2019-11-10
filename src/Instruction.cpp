#include "Instruction.h"

#include <iostream>

using namespace std;

size_t Add8Instruction::execute(IVirtualMachine &vm, IByteCode &) {
    cout << "execute Add8" << endl;

    auto a = vm.pop8();
    auto b = vm.pop8();
    vm.push8(a + b);

    return 1;
}

Add8Instruction::Add8Instruction(std::size_t address)
    : Instruction(address) {

}

size_t Instruction::execute(IVirtualMachine &, IByteCode &) {
    return 1;
}

Instruction::Instruction(std::size_t address)
    : _instruction_address(address) {

}

NopInstruction::NopInstruction(std::size_t address)
    : Instruction(address) {

}

Push8Instruction::Push8Instruction(std::size_t address)
    : Instruction(address) {

}

size_t Push8Instruction::execute(IVirtualMachine &vm, IByteCode &bc) {
    cout << "execute Push8" << endl;

    auto data = vm.readMemoryRelative8(1);
    cout << "push " << data << endl;
    vm.push8(data);

    return 2;
}

StopInstruction::StopInstruction(std::size_t address)
    : Instruction(address) {
}

size_t StopInstruction::execute(IVirtualMachine &vm, IByteCode &) {
    cout << "execute Stop" << endl;
    vm.stop();

    return 0;
}
