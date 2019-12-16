#ifndef SVM_INSTRUCTION_H
#define SVM_INSTRUCTION_H

#include <cstddef>

class IVirtualMachine;
class IDisassembler;
class Instruction {
public:
    virtual ~Instruction() = default;

    virtual void execute(IVirtualMachine &) = 0;
    virtual void disassembly(IDisassembler &) = 0;

protected:
    explicit Instruction() = default;
};

class Add8Instruction : public Instruction
{
public:
    explicit Add8Instruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler) override;
};

class Push8Instruction : public Instruction
{
public:
    explicit Push8Instruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler) override;
};

class JmpInstruction : public Instruction
{
public:
    explicit JmpInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler) override;
};

class JzInstruction : public Instruction
{
public:
    explicit JzInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler) override;
};

//class NopInstruction : public Instruction
//{
//public:
//    explicit NopInstruction() = default;
//};

class StopInstruction : public Instruction
{
public:
    explicit StopInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler) override;
};

#endif //SVM_INSTRUCTION_H
