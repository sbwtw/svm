
#include <iostream>
#include <cassert>

#include "VirtualMachine.h"
#include "ByteCode.h"
#include "Disassembler.h"

using namespace std;

int main()
{
    // means 1 + 2
    const char *code = "\x01\x01\x04\x06\x01\x03\x04\x06\x08";
//    const char *code = "\x01\x01\x04\x06\x01";
    ByteCode bc(code);

    IDisassembler *disassembler = new Disassembler(code);
    disassembler->disassembly(cout, bc);
    delete disassembler;

//    VirtualMachine vm;
//
//    vm.run(bc);
//
     // 1 + 2 = 3
//    assert(3 == vm.readStack8(0));

    return 0;
}
