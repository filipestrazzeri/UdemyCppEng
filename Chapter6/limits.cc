#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#include <iostream>
#include <limits>
#include <cstdint>

template <typename T>
void print_type_properties()
{
    std::cout << "min=" << std::numeric_limits<T>::min() << '\n'
              << "max=" << std::numeric_limits<T>::max() << '\n'
              << "bits=" << std::numeric_limits<T>::digits << '\n'
              << "decdigits=" << std::numeric_limits<T>::digits10 << '\n'
              << "integral=" << std::boolalpha << std::numeric_limits<T>::is_integer << '\n'
              << "signed=" << std::boolalpha << std::numeric_limits<T>::is_signed << '\n'
              << "exact=" << std::boolalpha << std::numeric_limits<T>::is_exact << '\n'
              << "infinity=" << std::boolalpha << std::numeric_limits<T>::has_infinity << '\n'<< '\n';
}

bool equal(const float x, const float y)
{
    return x == y;
}

bool almost_equal(const float x, const float y)
{
    return std::abs(x - y) <= std::numeric_limits<float>::epsilon();
}

int main()
{
    print_type_properties<std::int8_t>();
    print_type_properties<std::int32_t>();
    print_type_properties<float>();

    auto d1 = 0.2;
    auto d2 = 1 / (std::sqrt(5) * std::sqrt(5)); // == 1 / 5

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    std::cout.precision(17);

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    std::cout << "d1 == d2? " << std::boolalpha << equal(d1, d2) << std::endl;

    std::cout << "epsilon = " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "d1 ~= d2? " << std::boolalpha << almost_equal(d1, d2) << std::endl;

    return 0;
}
