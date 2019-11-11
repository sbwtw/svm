#ifndef SVM_INSTRUCTION_H
#define SVM_INSTRUCTION_H

#include <cstddef>

#include "src/IVirtualMachine.h"

class Instruction {
public:
    virtual size_t execute(IVirtualMachine &);

protected:
    explicit Instruction() = default;
};

class Add8Instruction : public Instruction
{
public:
    explicit Add8Instruction() = default;

    size_t execute(IVirtualMachine &vm) override;
};

class Push8Instruction : public Instruction
{
public:
    explicit Push8Instruction() = default;

    size_t execute(IVirtualMachine &vm) override;
};

class NopInstruction : public Instruction
{
public:
    explicit NopInstruction() = default;
};

class StopInstruction : public Instruction
{
public:
    explicit StopInstruction() = default;

    size_t execute(IVirtualMachine &vm) override;
};

#endif //SVM_INSTRUCTION_H
