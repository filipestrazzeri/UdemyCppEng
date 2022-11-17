#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::pair p1{42, "demo"};   // std::pair<int, std::string>
    std::pair p2{"demo", 42};   // std::pair<std::string, int>
    std::pair p3{"42", "demo"}; // std::pair<std::string, std::string>

    return 0;
}
