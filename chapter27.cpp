#include <iostream>

// static specifier
// object can have a static storage duration
// The memory space for static objects is allocated when the program starts
// and deallocated when the program ends

void afunction()
{
    static int a = 0; // declare a static varible, it only be called once during the entire program
    a++;
    std::cout << "a is : " << a << '\n';
}
class MyClass
{
public:
    static int x;                     // a static data member, live independently of an object of a class
    static int class_function(int a); // a static function member
};
int MyClass::x = 6;                // define a member outside class
int MyClass::class_function(int a) // define a function outside class
{
    return a;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        afunction(); // a is not initialized everytime the function run
    }
    MyClass::x = 7;
    std::cout << "X is: " << MyClass::x << '\n';
    std::cout << "A is: " << MyClass::class_function(MyClass::x) << '\n';
}