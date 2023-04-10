#include <iostream>
#include <cstdint>
enum class Status
{
    Unknown,
    Connected,
    Disconnected

};
struct User
{
    Status status;
    std::uint64_t id;

}; // ; Also needed for structs


/// AAA: Almost Always Auto
/// DRY: Don't Repeat Yourself
/*
    Autos Allow us let the compiler decide what a data type should be
    but it also lets us know if we are doing something wrong or if we will have say narrowing / data loss

*/

int main()
{
    float a = 10.0F;
    auto e = std::int32_t{a};
    auto user1 = User{.status = Status::Unknown, .id = 32U};

    return 0;
}
