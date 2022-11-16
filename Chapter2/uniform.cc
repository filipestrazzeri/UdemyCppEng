#include <iostream>
#include <string>

int main()
{
    std::string s1("test");  // direct initialization
    std::string s2 = "test"; // copy initialization

    std::string s3{s1};    // direct-list-initialization
    std::string s4 = {s2}; // copy-list-initialization

    auto s5{s1};               // direct-list-initialization
    auto s6 = std::string{s2}; // copy-list-initialization

    return 0;
}
