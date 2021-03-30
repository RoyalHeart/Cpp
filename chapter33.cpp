#include <iostream>

// conversions
// types can be convert into other types

// implicit conversions
// convert double to int can cause some infomation lost(the decimal part)
// when smaller intergers types(char) used in arithmetic operation,
// they promoted to integers
// any type can convert to boolean: if they are not 0 they become true and otherwise
// an array get convert to pointer of the first element -> prefer vector and array containers

// explicit conversions
// dynamic_cast: converts pointers of base class to pointers to derived class,
// and vice versa up the inheritance chain
// reintrepret_cast is avoided as it does not guarantee of any kind
// use static_cast most of the time
class Base
{
public:
    virtual ~Base() {}
};
class Derive : public Base
{
};

int main()
{
    int i = 33;
    double d = 33.3;
    i = d; // convert double to int
    char c1 = 3;
    char c2 = 3;
    auto result = c1 + c2; // result is of int type
    bool b = i;            // convert int to boolean
    int *iptr = &i;
    void *vptr = iptr;                     // int pointer convert to void pointer
    int *iptr2 = static_cast<int *>(vptr); // cast void pointer to int pointer
    std::cout << "int pointer: " << *iptr2 << '\n';
    std::cout << "I is: " << i << '\n';
    std::cout << "B is: " << b << '\n';

    Base *base = new Derive;
    Base *base1 = new Base;
    Derive *derive = new Derive;

    if (dynamic_cast<Derive *>(base)) // check if base can be cast to Derive
    {
        std::cout << "Yes" << '\n';
    }
    else
    {
        std::cout << "No" << '\n';
    }
    if (dynamic_cast<Derive *>(base1)) // check base1 can cast to Derive
    {
        std::cout << "Yes" << '\n';
    }
    else
    {
        std::cout << "No" << '\n';
    }
    if (dynamic_cast<Base *>(derive)) // check derive can cast to Base
    {
        std::cout << "Yes" << '\n';
    }
    else
    {
        std::cout << "No" << '\n';
    }

    delete base;
    delete derive;
}