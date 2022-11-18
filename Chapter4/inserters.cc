#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    const auto my_vector = std::vector{0, 1, 2, 3, 4, 5};
    auto my_result1 = std::vector<int>{};
    auto my_result2 = std::vector<int>{};

    // container must implement "insert"
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::inserter(my_result1, my_result1.end()));
    for (const auto val : my_result1)
        std::cout << val << " ";
    std::cout << '\n';
    my_result1.clear();

    // container must implement "push_back"
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::back_inserter(my_result1));
    for (const auto val : my_result1)
        std::cout << val << " ";
    std::cout << '\n';
    my_result1.clear();

    return 0;
}
