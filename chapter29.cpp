#include <iostream>

// Enumeration (enum)
// is a type whose values are user-defined named constants called enumerators
// unscoped and scoped enum
// prefer scoped enum than unscoped enum
// use enumerations when our object is to have one value out of a set of predefinednamed values
enum MyEnum // unscoped enum
{
    myfirstvalue = 29,
    mysecondvalue = 299,
    mythirdvalue
};
enum class My_Enum : int // scoped enum with underlying type
{
    first = 10,
    second,
    third
};
int main()
{
    MyEnum a_enum = myfirstvalue; // create an enum type variable
    a_enum = mysecondvalue;       // change the value of enum type variable
    std::cout << a_enum << '\n';
    My_Enum b_enum = My_Enum::first;
    std::cout << (int)b_enum << '\n';
}