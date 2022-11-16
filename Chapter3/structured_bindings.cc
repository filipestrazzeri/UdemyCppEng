#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, std::string, double> find()
{
    return std::make_tuple(1, "marius", 1234.5);
}

int main()
{
    auto [id, name, score] = find();

    if (auto [id, name, score] = find(); score > 1000)
    {
        std::cout << name << '\n';
    }

    int arr[] = {1, 2};
    auto [a, b] = arr;
    auto &[x, y] = arr;

    return 0;
}
