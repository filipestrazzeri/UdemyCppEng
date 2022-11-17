#include <chrono>
#include <iostream>
#include <format>

using namespace std::chrono_literals;

int main()
{
    std::chrono::hours half_day(12);
    std::chrono::minutes half_hour(30);
    std::chrono::seconds half_minute(30);
    std::chrono::milliseconds half_second(500);
    std::chrono::microseconds half_millisecond(500);
    std::chrono::nanoseconds half_microsecond(500);

    // format: year / month /day
    std::chrono::year_month_day d1 = 2020y / 1 / 15;
    std::chrono::year_month_day d2 = 2020y / std::chrono::January / 15;
    // format: day / month / year
    std::chrono::year_month_day d3 = 15d / 1 / 2020;
    std::chrono::year_month_day d4 = 15d / std::chrono::January / 2020;
    // format: month / day / year
    std::chrono::year_month_day d5 = 1 / 15d / 2020;
    std::chrono::year_month_day d6 = std::chrono::January / 15 / 2020;

    auto time = std::chrono::zoned_time{std::chrono::current_zone(),
                                        std::chrono::system_clock::now()};
    std::cout << time << '\n';

    auto time2 = std::chrono::zoned_time{std::chrono::locate_zone("Asia/Tokyo"),
                                         std::chrono::system_clock::now()};
    std::cout << time2 << '\n';

    return 0;
}
