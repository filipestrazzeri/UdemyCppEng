#include <iostream>
#include <string>

namespace
{
void print(std::string message)
{
    std::cout << message << '\n';
}
} // namespace

void file1_run()
{
    print("run");
}

int main()
{
    file1_run();

    return 0;
}
