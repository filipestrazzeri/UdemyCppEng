#include <iostream>

struct foo3_
{
    char a;        // 1 byte
    char _pad0[3]; // 3 bytes padding to put b on a 4-byte boundary
    int b;         // 4 bytes
};

struct foo4 // size = 24, alignment = 8
{           // foo4: +--------+--------+--------+--------+
    int a;  // members: |aaaab...|cccc....|dddddddd|e.......|
    char b; // . represents a byte of padding
    float c;
    double d;
    bool e;
};

struct alignas(4) foo1
{
    char a;
    char b;
};

struct foo2
{
    char a;
    char b;
    char _pad0[2];
};

int main()
{

    return 0;
}
