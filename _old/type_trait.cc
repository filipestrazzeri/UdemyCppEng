#include <iostream>
#include <string>
#include <type_traits>

using namespace std::string_literals;

template <typename T,
          typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
T multiply1(T const t1, T const t2)
{
    return t1 * t2;
}

template <typename T>
T multiply2(T const t1, T const t2)
{
    static_assert(std::is_arithmetic_v<T>, "Type is not arith!");

    return t1 * t2;
}

template <typename T>
auto process(T arg)
{
    if constexpr (std::is_same_v<T, bool>)
        return !arg;
    else if constexpr (std::is_integral_v<T>)
        return -arg;
    else if constexpr (std::is_floating_point_v<T>)
        return std::abs(arg);
    else
        return arg;
}

template <typename T>
struct is_void
{
    static const bool value = false;
};

template <>
struct is_void<void>
{
    static const bool value = true;
};

int main()
{
    auto v1 = multiply1(42.0, 1.5); // OK
    auto v2 = multiply2(42.0, 1.5); // OK
    auto v3 = process(-42.0);       // v3 = 42.0

    return 0;
}
