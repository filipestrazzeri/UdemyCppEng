#include <iostream>
#include <cstdint>

int main()
{

    bool b1 = true;
    bool b2 = false;

    if (b1)
    {

        std::cout << "Print printy!\n";
    }
    else if (!b2)
    {

        std::cout << "b2 is false!\n";
    }
    else
    {

        std::cout << "else statement!\n";
    }



    // Non ternary
    std::int32_t result;

    if (b1) {

        result = 10;
    }
    else {

        result = -10;
    }


    // Ternary
    std::int32_t result2 = b1 ? 10 : -10;

    return 0;
}
