#include <iostream>
#include <cstdint>

int main()
{

    int i = 15; //We should not use this in mordern C++
                // Different OS and compilers can interpret this data as different sizes

    std::int8_t i1;
    std::uint8_t i2 = 0U; // you could use a u or U to signify its unsigned

    std::int16_t i1;
    std::uint16_t i2 = 0U;

    std::int32_t i1;
    std::uint32_t i2 = 0U;

    std::int64_t i1;
    std::uint64_t i2 = 0U;


    float f1 = 0.0F;     // 32bit
    double f2 = 0.0;    // 64bit

    char c1 = 'A'; // Use single quotes for characters
    char c2 = 'b'; // These get mapped to integer values in ASCII

    return 0;
}
