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


int main()
{

    print_type_properties<std::int8_t>();
    print_type_properties<std::int32_t>();
    print_type_properties<float>();

    return 0;
}
