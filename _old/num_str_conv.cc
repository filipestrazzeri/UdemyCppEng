#include <iostream>
#include <string>

int main()
{
    auto si = std::to_string(42);      // si="42"
    auto sl = std::to_string(42L);     // sl="42"
    auto su = std::to_string(42u);     // su="42"
    auto sd = std::to_wstring(42.0);   // sd=L"42.000000"
    auto sld = std::to_wstring(42.0L); // sld=L"42.000000"

    auto i1 = std::stoi("42");                 // i1 = 42
    auto i2 = std::stoi("101010", nullptr, 2); // i2 = 42
    auto i3 = std::stoi("052", nullptr, 8);    // i3 = 42
    auto i4 = std::stoi("0x2A", nullptr, 16);  // i4 = 42


    auto d1 = std::stod("123.45");       // d1 = 123.45000000000000
    auto d2 = std::stod("1.2345e+2");    // d2 = 123.45000000000000
    auto d3 = std::stod("0xF.6E6666p3"); // d3 = 123.44999980926514

    return 0;
}
