
#include <iostream>
#include <cassert>

#include "VirtualMachine.h"
#include "ByteCode.h"

using namespace std;

int main()
{
    // means 1 + 2
    const char *code = "\x01\x01\x01\x02\x02\x00";

    ByteCode bc(code);
    VirtualMachine vm;

    vm.run(bc);

    // 1 + 2 = 3
    assert(3 == vm.readStackAbsolute8(0));

    return 0;
}
