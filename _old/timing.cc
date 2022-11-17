#include <chrono>
#include <format>
#include <iostream>

using namespace std::chrono_literals;

template <typename Time = std::chrono::microseconds,
          typename Clock = std::chrono::high_resolution_clock>
struct perf_timer
{
    template <typename F, typename... Args>
    static Time duration(F &&f, Args... args)
    {
        const auto start = Clock::now();
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
        const auto end = Clock::now();
        return std::chrono::duration_cast<Time>(end - start);
    }
};

void func(int const count = 100000000)
{
    for (int i = 0; i < count; ++i)
        ;
}

int main()
{
    auto t = perf_timer<>::duration(func, 100000000);
    std::cout << std::chrono::duration<double, std::milli>(t).count() << "ms"
              << '\n';
    std::cout << std::chrono::duration<double, std::micro>(t).count() << "us"
              << '\n';

    return 0;
}
