#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
class _lambda1
{
public:
    bool operator()(const T n) const
    {
        return n > 0;
    }
};

template <typename T>
class _lambda2
{
    int minimum_;
    int maximum_;

public:
    explicit _lambda2(const T minimum, const T maximum)
        : minimum_(minimum), maximum_(maximum)
    {
    }
    _lambda2(const _lambda2 &) = default;
    _lambda2(_lambda2 &&) = default;
    _lambda2 &operator=(const _lambda2 &) = delete;
    ~_lambda2() = default;
    bool operator()(const T n) const
    {
        return minimum_ <= n && n <= maximum_;
    }
};


int main()
{
    auto numbers = std::vector<int>{0, 2, -3, 5, -1, 6, 8, -4, 9};
    auto is_positive = [](const auto n) { return n > 0; };
    auto positives =
        std::count_if(std::begin(numbers), std::end(numbers), is_positive);

    const int minimum = 1;
    const int maximum = 2;

    auto is_in_range = [minimum, maximum](const auto n) {
        return minimum <= n && n <= maximum;
    };

    auto vi = std::vector<int>{1, 1, 2, 3, 5, 8};
    auto tl = []<typename T>(std::vector<T> const &vec) {
        std::cout << std::size(vec) << '\n';
    };
    tl(vi); // OK, prints 6
    // tl(42); // error

    return 0;
}
