#include <cstdint>
#include <iostream>

#include "lib.h" // this links the cpp with the h as a compile unit

void printer(std::int32_t value)
{
    std::cout << value << '\n';
}
