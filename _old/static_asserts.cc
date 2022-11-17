#include <iostream>
#include <type_traits>

template <typename T>
auto mul(T const a, T const b)
{
    static_assert(std::is_integral_v<T>, "Integral type expected");
    return a * b;
}

int main()
{
    auto v1 = mul(1, 2);       // OK
    auto v2 = mul(12.0, 42.5); // error: Integral type expected

    return 0;
}
