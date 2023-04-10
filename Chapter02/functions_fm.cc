#include <iostream>
#include <cstdint>

// FUNCTIONS
// The compiler goes from top to bottom this is important to know


void print_hello_world()
{
    std::cout << "Hello World\n";
}


// FORWARD DELCARING
// This bypasses any ordering issue in files

void printer(std::int32_t value);

int main()
{
    printer(42);
    print_hello_world();
    return 0;
}

void printer(std::int32_t value)
{
    std::cout << value << "\n";
}
