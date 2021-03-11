#include <iostream>

int main(void)
{
    // create a pointer of int type
    int *ptr;
    int a = 500;
    // the pointer point to the a address, ptr have the value of a address
    ptr = &a;
    std::cout << "*ptr = " << *ptr << std::endl;
    *ptr = 400;
    std::cout << "a = " << a;
}
// result:
// ptr holds the value: 500
// a holds the value: 400