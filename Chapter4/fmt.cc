#include <chrono>
#include <format>
#include <iostream>

int main()
{
    std::cout << std::format("{} is {}", "John", 42) << '\n';
    std::cout << std::format("{0} is {1}", "John", 42) << '\n';

    std::cout << std::format("{0} hex is {0:08X}", 42) << '\n';

    char buf[100]{};
    std::format_to_n(buf, sizeof(buf), "{} is {}", "John", 42);
    std::cout << buf << '\n';

    return 0;
}
