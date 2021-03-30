#include <iostream>

// template
// use for generic programming
// (define a function or a class without worrying about what types it accepts)
// use templates when we want to define a class or a function that can accept almost any type
// can use with many member of a class inside or outside
// can have
template <typename T, typename U> // create a type T, which is any type, can have many parameter
                                  // create a type U, which is any type

void a_function(T param, U param2) // function use template
{
    std::cout << "T type parameter is: " << param << '\n';
    std::cout << "U type parameter is: " << param2 << '\n';
}
template <> // specialization
void a_function(int param, int param2)
{
    std::cout << "Use int type: " << param << '\n';
    std::cout << "Use int type: " << param2 << '\n';
}
template <typename T>
class A_class
{
private:
    T t;

public:
    A_class(T t)
    {
        this->t = t;
    }
    T getT()
    {
        return this->t;
    }
};

int main()
{
    a_function<int, double>(28, 28.8); // the same param argument can have many type
    a_function<std::string, int>("hello", 28);
    a_function<double, double>(28.8, 28.9);
    a_function<int, int>(7, 8); // invoke specialization
    A_class<int> object(5);
    A_class<std::string> object2("hi");
    int t = object.getT();
    std::string s = object2.getT();
    std::cout << "T int in class is: " << t << '\n';
    std::cout << "T string in class is: " << s << '\n';
}