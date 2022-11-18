#include <iostream>
#include <optional>
#include <string>

using namespace std::string_literals;

std::optional<std::string> check(const bool flag)
{
    if (flag)
        return "true"s;
    return {};
}

int main()
{
    std::optional<int> v1{42};
    std::cout << *v1 << '\n'; // 42

    std::optional<std::string> v2{"text"s};
    std::cout << v2.value() << '\n'; // text
    std::optional<std::string> v3;
    std::cout << v3.value_or("default"s) << '\n'; // default

    std::cout << std::boolalpha << v3.has_value() << '\n';

    return 0;
}
