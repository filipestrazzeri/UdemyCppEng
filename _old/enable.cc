#include <iostream>
#include <type_traits>

template <typename T>
auto mul(T const a, T const b)
{
    static_assert(std::is_integral_v<T>, "Integral type expected");
    return a * b;
}

template <typename T,
          typename = typename std::enable_if_t<std::is_integral_v<T>, T>>
T mul2(T const a, T const b)
{
    return a * b;
}

int main()
{
    auto v1 = mul(1, 2);       // OK
    // auto v2 = mul(12.0F, 42.5F); // error: Integral type expected
    auto v3 = mul2(1, 2);       // OK
    // auto v4 = mul2(12.0F, 42.5F);

    return 0;
}
