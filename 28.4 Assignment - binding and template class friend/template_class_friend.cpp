#include <iostream>

// class using template
template <class T>
class A
{
public:
    // constructor
    A(T a = 0) : m_a(a) {}

    // a friend function with data type as class, function name foo, and parameter is object of a class
    // friend function can have all the private and protected properties
    // template is just for flexible datatype
    template <class U>
    friend A<U> foo(A<U> &a);

    // a friend class can also have all the private and protected properties of the base class
    friend class B;

private:
    T m_a;
    int a = 9;
};

// define function outside of class
template <class U>
A<U> foo(A<U> &a)
{
    return a;
}

// class B is friend of class A
class B
{
private:
    int b = 0;

public:
    // constructor
    B(int b)
    {
        this->b = b;
    }
    // a function using template
    template <typename T>
    A<T> print_value(A<T> obj)
    {
        std::cout << obj.a << '\n'; // class B access the private value from class A
        return obj;
    }
};

int main()
{
    A<int> a(6);
    A<double> c(6);
    B b(7);
    b.print_value(a);
    b.print_value(c);
    foo(a);
}