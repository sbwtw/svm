#ifndef SVM_INSTRUCTION_H
#define SVM_INSTRUCTION_H

#include <cstddef>
#include <ostream>

class IVirtualMachine;
class IDisassembler;
class Instruction {
public:
    virtual ~Instruction() = default;

    virtual void execute(IVirtualMachine &) = 0;
    virtual void disassembly(IDisassembler &, std::ostream &out) = 0;

protected:
    explicit Instruction() = default;
};

class Add8Instruction : public Instruction
{
public:
    explicit Add8Instruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &, std::ostream &out) override;
};

class Push8Instruction : public Instruction
{
public:
    explicit Push8Instruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler, std::ostream &out) override;
};

class JmpInstruction : public Instruction
{
public:
    explicit JmpInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler, std::ostream &out) override;
};

class JzInstruction : public Instruction
{
public:
    explicit JzInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler, std::ostream &out) override;
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
    void disassembly(IDisassembler &disassembler, std::ostream &out) override;
};

class B2WInstruction : public Instruction
{
public:
    explicit B2WInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler, std::ostream &out) override;
};

class W2DInstruction : public Instruction
{
public:
    explicit W2DInstruction() = default;

    void execute(IVirtualMachine &vm) override;
    void disassembly(IDisassembler &disassembler, std::ostream &out) override;
};

#endif //SVM_INSTRUCTION_H
