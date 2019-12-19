#include "Instruction.h"
#include "src/IVirtualMachine.h"
#include "src/Disassembler.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Add8Instruction::execute(IVirtualMachine &vm) {
    cout << "execute Add8" << endl;

    auto a = vm.pop8();
    auto b = vm.pop8();
    auto r = a + b;
    vm.push8(r);
    vm.cpuState().zero_flag = r == 0;
    vm.cpuState().instruction_ptr += 1;
}

void Add8Instruction::disassembly(IDisassembler &disassembler, ostream &out)
{
}

void Push8Instruction::execute(IVirtualMachine &vm) {
    cout << "execute Push8" << endl;

    auto data = vm.readMemoryRelative8(1);
    cout << "push " << (short)data << endl;
    vm.push8(data);
    vm.cpuState().instruction_ptr += 2;
}

void Push8Instruction::disassembly(IDisassembler &disassembler, ostream &out)
{
    int data = disassembler.read(1);

    out << "Push8\t" << setw(2) << setfill('0') << hex << data;

    disassembler.offset += 2;
}

void StopInstruction::execute(IVirtualMachine &vm) {
    cout << "execute Stop" << endl;
    vm.stop();
}

void StopInstruction::disassembly(IDisassembler &disassembler, ostream &out) {

}

void JmpInstruction::execute(IVirtualMachine &vm) {
    auto offset = vm.pop8();

    vm.cpuState().instruction_ptr += offset + 1;
}

void JmpInstruction::disassembly(IDisassembler &disassembler, ostream &out) {

}

void JzInstruction::execute(IVirtualMachine &vm) {
    auto& cpu = vm.cpuState();
    auto offset = vm.pop8();

    if (cpu.zero_flag)
        cpu.instruction_ptr += offset;

    cpu.instruction_ptr += 1;
}

void JzInstruction::disassembly(IDisassembler &disassembler, ostream &out) {

}

void B2WInstruction::disassembly(IDisassembler &disassembler, std::ostream &out)
{
    out << "B2W";
    disassembler.offset += 1;
}

void B2WInstruction::execute(IVirtualMachine &vm)
{

}

void W2DInstruction::execute(IVirtualMachine &vm) {

}

void W2DInstruction::disassembly(IDisassembler &disassembler, std::ostream &out)
{
    out << "W2D";
    disassembler.offset += 1;
}
