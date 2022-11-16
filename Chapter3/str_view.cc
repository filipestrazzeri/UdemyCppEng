#include <iostream>
#include <string>
#include <string_view>

/**
 The function parameter is a constant std::string reference, but the function is
 called with a string literal, which means std::string needs to be constructed
 from the literal
 */
std::string get_filename1(const std::string &str)
{
    auto const pos1{str.find_last_of('\\')};
    auto const pos2{str.find_last_of('.')};
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

std::string_view get_filename2(std::string_view str)
{
    auto const pos1{str.find_last_of('\\')};
    auto const pos2{str.find_last_of('.')};
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

int main()
{
    auto name1 = get_filename1(R"(c:\test\example1.doc)"); // example1
    auto name2 = get_filename1(R"(c:\test\example2)");     // example2
    std::cout << name1 << '\n';
    std::cout << name2 << '\n';

    auto name3 = get_filename2(R"(c:\test\example1.doc)"); // example1
    auto name4 = get_filename2(R"(c:\test\example2)");     // example2
    std::cout << name3 << '\n';
    std::cout << name4 << '\n';

    return 0;
}
