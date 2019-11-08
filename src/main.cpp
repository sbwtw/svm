
#include <iostream>
#include <stack>

#include "VirtualMachine.h"
#include "ByteCode.h"

using namespace std;

int main()
{
    ByteCode bc;
    VirtualMachine vm;

    vm.run(bc);

    return 0;
}
