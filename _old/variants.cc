#include <iostream>
#include <string>
#include <variant>

using namespace std::string_literals;


int main()
{
    std::variant<int, double, std::string> v = 42;
    auto i1 = std::get<int>(v);
    auto i2 = std::get<0>(v);
    std::cout << i1 << '\n';
    std::cout << i2 << '\n';

    try
    {
        auto f = std::get<double>(v);
    }
    catch (std::bad_variant_access const &e)
    {
        std::cout << e.what() << '\n'; // Unexpected index
    }

    return 0;
}
