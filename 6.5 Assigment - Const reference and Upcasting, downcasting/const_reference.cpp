#include <iostream>

template <class T>
class Wrapper
{
private:
    T value_;

public:
    // constructor
    Wrapper(T const &value) : value_(value) {}

    T const &get()
    {
        return value_;
    }
};

void test1()
{
    int a = 5;
    using IntRefWrapper = Wrapper<int>; // template T is int
    IntRefWrapper intRefWrapper(a);     // a is int
    // intRefWrapper.get() = 6;  // read only, cannnot use this way
    std::cout << "a is now " << a << '\n';
}
void test2()
{
    int a = 5;
    using IntRefWrapper = Wrapper<int &>; // template T is int&
    IntRefWrapper intRefWrapper(a);       // a is int&
    intRefWrapper.get() = 6;              // 6 is pass in as a int&
    // so eventhough it is const to an int&, it is acctually just int& and can be change not const
    // should be careful to use these const of reference becuase it is not const
    std::cout << "a is now " << a << '\n';
}

int main()
{
    test1();
    test2();
}
