# svm
S-lang Virtual Machine, 一种栈式虚拟机

## Operand Code
|   Name    |   Code   |    Description                          |
|-----------|----------|-----------------------------------------|
|   Nop     |   0x00   |                                         |
|   Psh8    |   0x01   | Push 8bit data                          |
|   Pop8    |   0x02   |                                         |
|   Dup8    |   0x03   |                                         |
|   B2W     |   0x04   | Convert BYTE to WORD                    |
|   SB2W    |   0x05   | Convert Signed BYTE to WORD             |
|   W2D     |   0x06   | Convert WORD to DWORD                   |
|   SW2D    |   0x07   | Convert Signed WORD to DWORD            |
|   Add32   |   0x08   | 32Bit Add                               |
|   AddR32  |   0x09   | 32Bit Real Add                          |
|   Sub32   |   0x0A   | 32Bit Sub                               |
|   SubR32  |   0x0B   | 32Bit Real Sub                          |
|   Mul     |          |                                         |
|   Div     |          |                                         |
|   Mod     |          |                                         |
|   Deref   |          |                                         |
|   Jmp     |          |                                         |
|   Int     |          |                                         |
