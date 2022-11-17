#include <iostream>

struct foo1
{
    // conversion constr
    foo1(const int a) : m_a(a)
    {
        std::cout << "foo(a)" << '\n';
    }

    // conversion operator
    operator bool() const
    {
        return true;
    }

    int m_a;
};

void bar1(const foo1 f)
{
    (void)f;
}

struct foo2
{
    explicit foo2(const int a) : m_a(a)
    {
        std::cout << "foo(a)" << '\n';
    }

    explicit operator bool() const
    {
        return true;
    }

    int m_a;
};

void bar2(const foo2 f)
{
    (void)f;
}

int main()
{
    bar1(1);
    // bar2(1);

    return 0;
}
