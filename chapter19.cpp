#include <iostream>
#include <string>

// this is a function, it has a return type, a name, a (list) of parameter and a body of statements
// a function can be declared like below
// to use a function, it must be declared before the main function : void a_function();
// the function which has a type must return a value of that type
// void function do not need to return a value

void a_function(int a_parameter)
{
    std::cout << "This is the parameter of the function: " << ++a_parameter << '\n';
}

// declaration of function:
void reference_function(int &byreference);
void const_reference_function(std::string &byconstreference);
void print_auto(int num);
void print_auto(char c);
void print_auto(double b);

// a function can have many return statements, if any of those are executed the function stop
int main(void)
{
    int a = 1;
    a_function(9);         // call the function and pass 9 as a parameter (function argument)
    a_function(a);         // pass variable a to the function, the copy of it will be use in the function
    reference_function(a); // passing by reference, the argument will be used itself

    std::string s = "Hi, how are you?";
    const_reference_function(s); // passing by const reference is for efficiency

    print_auto(6); // overload functions is selected based on the type of arguments
    print_auto('a');
    print_auto(6.7);
}

// a function with reference argument
void reference_function(int &byreference)
{
    byreference++;
    std::cout << "The argument passed by reference is: " << byreference << '\n';
}

// a function with const reference argument
void const_reference_function(std::string &byconstreference)
{
    std::cout << "The argument passed by const reference is: " << byconstreference << '\n';
}

// function overload: functions can have the same name but different parameter types
void print_auto(int num)
{
    std::cout << "The integer is: " << num << '\n';
}
void print_auto(char c)
{
    std::cout << "The character is: " << c << '\n';
}
void print_auto(double b)
{
    std::cout << "The double is: " << b << '\n';
}
