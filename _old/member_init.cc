#include <iostream>

struct foo
{
    foo()
    {
        std::cout << "default constructor\n";
    }
};

struct bar
{
    foo m_foo;
    bar(const foo _foo)
    {
        m_foo = _foo;
    }
    // bar(const foo _foo) : m_foo(_foo)
    // {
    // }
};

int main()
{
    auto f = foo{};
    auto b = bar{f};

    return 0;
}
