#ifndef SVM_INSTRUCTION_H
#define SVM_INSTRUCTION_H

#include <cstddef>

#include "src/IVirtualMachine.h"

class Instruction {
public:
    virtual size_t execute(IVirtualMachine &);

    [[nodiscard]]
    std::size_t instructionAddress() const { return _instruction_address; }

protected:
    explicit Instruction(std::size_t address);

private:
    std::size_t _instruction_address = 0;
};

class Add8Instruction : public Instruction
{
public:
    explicit Add8Instruction(std::size_t address);

    size_t execute(IVirtualMachine &vm) override;
};

class Push8Instruction : public Instruction
{
public:
    explicit Push8Instruction(std::size_t address);

    size_t execute(IVirtualMachine &vm) override;
};

class NopInstruction : public Instruction
{
public:
    explicit NopInstruction(std::size_t address);
};

class StopInstruction : public Instruction
{
public:
    explicit StopInstruction(std::size_t address);

    size_t execute(IVirtualMachine &vm) override;
};

#endif //SVM_INSTRUCTION_H
