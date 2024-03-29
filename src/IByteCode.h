#ifndef SVM_IBYTECODE_H
#define SVM_IBYTECODE_H

#include <optional>
#include <memory>

#include "src/Instructions/Instruction.h"

class IByteCode {
public:
//    class iterator;
//    friend class iterator;

public:
    explicit IByteCode() = default;

    std::unique_ptr<Instruction> instruction(size_t address);

    virtual std::optional<uint8_t> read8(size_t address) = 0;
    virtual std::optional<uint32_t> read32(size_t address) = 0;

    // iterator
//    iterator begin();
//    iterator end();
};

//class IByteCode::iterator {
//public:
//    explicit iterator(IByteCode *ref);
//    explicit iterator(IByteCode *ref, std::optional<Instruction> next_instruction);
//
//    iterator operator++();
//    Instruction operator*();
//    bool operator!=(iterator &rhs);
//
//private:
//    IByteCode *ref;
//    std::optional<Instruction> next_inst;
//};

#endif //SVM_IBYTECODE_H
