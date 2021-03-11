#include <iostream>

int main(void)
{
    int x = 500;
    // create a integer y with the same address with x
    // y and x have the same value, an address has 2 names
    int &y = x;
    // create a integer z read-only with the same address with x
    const int &z = x;
    // can not use z = 400;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    y = 400;
    std::cout << "After change:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
}
// result:
// x = 500
// y = 500
// z = 500
// After change:
// x = 400
// y = 400
// z = 400