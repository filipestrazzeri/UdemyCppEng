#include <iostream>
#include <random>
#include <string>
#include <type_traits>

using namespace std::string_literals;

using long_type = std::conditional_t<sizeof(void *) <= 4, long, long long>;

template <int size>
using number_type = typename std::conditional_t<
    size <= 1,
    std::int8_t,
    typename std::conditional_t<
        size <= 2,
        std::int16_t,
        typename std::conditional_t<size <= 4, std::int32_t, std::int64_t>>>;

template <typename T,
          typename D = std::conditional_t<std::is_integral_v<T>,
                                          std::uniform_int_distribution<T>,
                                          std::uniform_real_distribution<T>>,
          typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
std::vector<T> GenerateRandom(T const min, T const max, size_t const size)
{
    std::vector<T> v(size);
    std::random_device rd{};
    std::mt19937 mt{rd()};
    D dist{min, max};
    std::generate(std::begin(v), std::end(v), [&dist, &mt] {
        return dist(mt);
    });
    return v;
}

template <bool Test, class T1, class T2>
struct conditional
{
    typedef T2 type;
};

template <class T1, class T2>
struct conditional<true, T1, T2>
{
    typedef T1 type;
};

int main()
{
    auto n = long_type{42};

    auto v1 = GenerateRandom(1, 10, 10);     // integers
    auto v2 = GenerateRandom(1.0, 10.0, 10); // doubles

    return 0;
}
