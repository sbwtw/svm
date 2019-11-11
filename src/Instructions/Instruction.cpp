#include "Instruction.h"

#include <iostream>

using namespace std;

size_t Add8Instruction::execute(IVirtualMachine &vm) {
    cout << "execute Add8" << endl;

    auto a = vm.pop8();
    auto b = vm.pop8();
    auto r = a + b;
    vm.push8(r);
    vm.cpuState().zero_flag = r == 0;

    return 1;
}

size_t Push8Instruction::execute(IVirtualMachine &vm) {
    cout << "execute Push8" << endl;

    auto data = vm.readMemoryRelative8(1);
    cout << "push " << data << endl;
    vm.push8(data);

    return 2;
}

size_t StopInstruction::execute(IVirtualMachine &vm) {
    cout << "execute Stop" << endl;
    vm.stop();

    return 0;
}

size_t JmpInstruction::execute(IVirtualMachine &vm) {
    auto offset = vm.pop8();

    vm.cpuState().instruction_ptr += offset;

    return 1;
}

size_t JzInstruction::execute(IVirtualMachine &vm) {
    auto& cpu = vm.cpuState();
    auto offset = vm.pop8();

    if (cpu.zero_flag)
        cpu.instruction_ptr += offset;

    return 1;
}
