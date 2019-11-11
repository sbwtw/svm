#ifndef SVM_INSTRUCTION_H
#define SVM_INSTRUCTION_H

#include <cstddef>

#include "src/IVirtualMachine.h"

class Instruction {
public:
    virtual size_t execute(IVirtualMachine &) = 0;
    virtual ~Instruction() = default;

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

class JmpInstruction : public Instruction
{
public:
    explicit JmpInstruction() = default;

    size_t execute(IVirtualMachine &vm) override;
};

class JzInstruction : public Instruction
{
public:
    explicit JzInstruction() = default;

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
