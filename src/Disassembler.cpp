#include "Disassembler.h"

#include <iomanip>

using namespace std;

void Disassembler::disassembly(ostream &out, IByteCode &bc) {

    while (true)
    {
        auto instruction = bc.instruction(offset);
        if (!instruction)
            break;

        instruction->disassembly(*this);
    }
//    _byte_code = &bc;
//
//    while (_running)
//    {
//        auto instruction = bc.instruction(_cpuState.instruction_ptr);
//
//        _cpuState.instruction_ptr += instruction->execute(*this);
//
//         dump stack
//        cout << "Stack: ";
//        for (auto v : _cpuState.stack)
//        {
//            cout << setw(2) << setfill('0') << hex << (short)v << ' ';
//        }
//        cout << endl;
//    }
//    for (offset = 0; byte_code[offset] != '\0'; ++offset) {
//
//        out << setw(2) << setfill('0') << hex << (short)byte_code[offset] << endl;
//    }
}

Disassembler::Disassembler(const char * bc)
    : byte_code(bc) {
}
