#include "Disassembler.h"

#include <iomanip>

using namespace std;

void Disassembler::disassembly(ostream &out, IByteCode &bc) {

    while (true)
    {
        auto instruction = bc.instruction(offset);
        if (!instruction)
            break;

        out << setw(4) << setfill('0') << hex << offset << '\t';
        instruction->disassembly(*this, out);
        out << endl;
    }
}

Disassembler::Disassembler(const char * bc)
    : byte_code(bc) {
}

uint8_t Disassembler::read(int offset)
{
    return byte_code[this->offset + offset];
}
