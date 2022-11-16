#include <iostream>

class Base
{
    virtual void foo() = 0;
    virtual void bar()
    {
    }
};

class Derived1 : public Base
{
    virtual void bar() override
    {
        std::cout << "Derived1\n";
    }
};

class Derived2 : public Derived1
{
    virtual void foo() override
    {
        std::cout << "Derived2\n";
    }
};

class Derived3 : public Derived1
{
    virtual void foo() final
    {
        std::cout << "Derived3\n";
    }
};

int main()
{

    return 0;
}
