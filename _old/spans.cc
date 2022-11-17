#include <iostream>
#include <span>
#include <string>

using namespace std::string_literals;

void func_old(int *const buffer, const size_t length)
{
}

void func_new(std::span<int> buffer)
{
}

int main()
{
    int arr1[] = {1, 1, 2, 3, 5, 8, 13};
    std::span<int, 7> s1{arr1};

    int arr2[] = {1, 1, 2, 3, 5, 8, 13};
    std::span<int> s2{arr2};

    return 0;
}
