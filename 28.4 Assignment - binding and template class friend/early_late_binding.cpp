#include <iostream>

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
// early binding is just like the way we use function before
// when compile, the compiler directly associate the identifier name with machine address
void early_binding()
{
    std::cout << "Early binding" << '\n';
    int a = 3;
    int b = 2;
    std::cout << add(a, b) << '\n';
    std::cout << subtract(a, b) << '\n';
    std::cout << multiply(a, b) << '\n';
}

// late binding by using pointer to a function
void late_binding()
{
    std::cout << '\n'
              << "Late binding" << '\n';
    int a = 3;
    int b = 2;
    // create a pointer to point to 3 function consecutively
    int (*pFunc)(int, int) = nullptr;
    pFunc = add;
    std::cout << pFunc(a, b) << '\n';
    pFunc = subtract;
    std::cout << pFunc(a, b) << '\n';
    pFunc = multiply;
    std::cout << pFunc(a, b) << '\n';
}

// Late binding is slightly less efficient since it involves an extra level of indirection
// However, the advantage of late binding is that it is more flexible than early binding,
// because decisions about what function to call do not need to be made until run time
int main()
{
    early_binding();
    late_binding();
}