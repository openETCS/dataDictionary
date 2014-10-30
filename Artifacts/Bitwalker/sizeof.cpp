#include <iostream>
#include "Locals.h"

int main()
{
    std::cout << sizeof(uint8_t*) << std::endl;
    std::cout << sizeof(unsigned int) << std::endl;
    std::cout << sizeof(BitwalkerLocals) << std::endl;

    return 1;
}

