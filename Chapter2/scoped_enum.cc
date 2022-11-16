#include <iostream>

enum class Status
{
    Unknown,
    Created,
    Connected
};

void process(const Status s)
{
    switch (s)
    {
        using enum Status;
    case Unknown: /*...*/
        break;
    case Created: /*...*/
        break;
    case Connected: /*...*/
        break;
    }
}

int main()
{
    Status s = Status::Created;

    enum Status2
    {
        Unknown,
        Created,
        Connected
    };
    auto s3 = Status2::Created; // error

    return 0;
}
