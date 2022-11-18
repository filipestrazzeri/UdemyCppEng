#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using ClockType = std::chrono::steady_clock;
using ClockRes = std::chrono::microseconds;

constexpr static auto NUM_ELEMENTS = 10U;

std::int32_t gen()
{
    static auto seed = std::random_device{};
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return dist(gen);
}

template <typename T>
void print_vector(const std::vector<T> &vec)
{
    for (const auto v : vec)
    {
        std::cout << v << '\n';
    }
    std::cout << '\n';
}

int main()
{
    auto my_vector = std::vector<std::int32_t>(NUM_ELEMENTS, 0U);
    std::generate(my_vector.begin(), my_vector.end(), gen);
    print_vector(my_vector);

    std::replace(my_vector.begin(), my_vector.end(), 0, 1000);
    print_vector(my_vector);

    std::replace_if(
        my_vector.begin(),
        my_vector.end(),
        [](const auto val) { return val == 2; },
        -1);
    print_vector(my_vector);

    std::sort(my_vector.begin(),
              my_vector.end(),
              [](const auto i, const auto j) { return i < j; });
    print_vector(my_vector);

    std::sort(my_vector.begin(),
              my_vector.end(),
              [](const auto i, const auto j) { return i > j; });
    print_vector(my_vector);

    // Pre C++20
    auto remove_it1 = std::remove(my_vector.begin(), my_vector.end(), -1);
    my_vector.erase(remove_it1, my_vector.end());
    print_vector(my_vector);

    auto remove_it2 = std::remove_if(my_vector.begin(),
                                     my_vector.end(),
                                     [](const auto i) { return i < 0; });
    my_vector.erase(remove_it2, my_vector.end());
    print_vector(my_vector);

    // Post C++20
    std::erase(my_vector, 7);
    print_vector(my_vector);
    std::erase_if(my_vector, [](const auto val) { return val == 10; });
    print_vector(my_vector);

    return 0;
}
