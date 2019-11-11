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

size_t Instruction::execute(IVirtualMachine &) {
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
