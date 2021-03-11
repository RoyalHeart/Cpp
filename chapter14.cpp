#include <iostream>

int main(void)
{
    // auto specifier can automatically deduce type
    auto a = 'c';     // type char
    auto b = 2;       // type int
    auto c = 123.456; // type double
    auto &d = c;      // d is of type double
    // use auto when it is hard to deduce manually or cumbersome to type
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
}
// result:
// a = c
// b = 2
// c = 123.456
// d = 123.456