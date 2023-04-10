#include <iostream>
#include <cstdint>

namespace // anonymous  can be used instead of static in front of the function
{
    constexpr std::uint64_t faculty(const std::uint8_t n)
    {
        auto result = std::uint64_t{};
        for (std::uint8_t i = 1; i <=n; i++)
        {
            result *= i;
        }

    }

}


// NAMESPACES
namespace MyStd
{
    enum class Status
    {
        Unknown,
        Connected,
        Disconnected

    }; // Defining an enum requires ; at the end of curly braces


    struct User
    {
        Status status;
        std::uint64_t id;

    }; // ; Also needed for structs
}


int main()
{

    MyStd::User user1 = {.status = MyStd::Status::Unknown, .id = 42U};
    std::cout << user1.id << '\n';
    std::cout << static_cast<std::int32_t>(user1.status) << '\n'; // Converts to an int, in this case 0 out of 3 values in the enum so could be 0 , 1 or 2

    return 0;
}
