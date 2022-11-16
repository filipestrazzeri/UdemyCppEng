#include <chrono>
#include <complex>
#include <iostream>
#include <string>

using namespace std::string_literals;
using namespace std::string_view_literals;
using namespace std::chrono_literals;
using namespace std::complex_literals;

int main()
{
    auto s1{"text"s};  // std::string
    auto s2{L"text"s}; // std::wstring
    auto s3{"text"sv}; // std::string_view

    auto timer{2h + 42min + 15s};
    auto year{2020y}; // std::chrono::year
    auto day{15d};    // std::chrono::day

    auto c{12.0 + 4.5i}; // std::complex<double>

    return 0;
}
