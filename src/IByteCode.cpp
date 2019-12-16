#include "IByteCode.h"
#include "src/Instructions/Instruction.h"

using namespace std;

//IByteCode::iterator::iterator(IByteCode *ref)
//    : ref(ref) {
//    if (ref)
//        next_inst = ref->next();
//}
//
//IByteCode::iterator IByteCode::iterator::operator++() {
//    next_inst = ref->next();
//
//    return *this;
//}
//
//bool IByteCode::iterator::operator!=(iterator &rhs) {
////    return next_inst != rhs.next_inst;
//
//    // next_inst is empty
//    if (!next_inst.has_value() && !rhs.next_inst.has_value())
//        return false;
//
//    return true;
//}
//
//Instruction IByteCode::iterator::operator*() {
//    return next_inst.value();
//}
//
//IByteCode::iterator::iterator(IByteCode *ref, std::optional<Instruction> next_instruction)
//    : ref(ref), next_inst(std::move(next_instruction)) {
//
//}
//
//IByteCode::iterator IByteCode::begin() {
//    return IByteCode::iterator(this);
//}
//
//IByteCode::iterator IByteCode::end() {
//    return IByteCode::iterator(nullptr);
//}

// instruction decode
unique_ptr<Instruction> IByteCode::instruction(size_t address) {
    auto op = read8(address);
    switch (op)
    {
    case 0x00: // stop
        return make_unique<StopInstruction>();
    case 0x01: // push
        return make_unique<Push8Instruction>();
    case 0x02: // add
        return make_unique<Add8Instruction>();
    case 0x04: // jz
        return make_unique<JzInstruction>();
    default:;
    }

    return make_unique<StopInstruction>();
}
