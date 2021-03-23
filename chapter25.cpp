#include <iostream>
// inheritance
// we can create a class inherited from a base class
// the inherit class can access public members of base class
// new access specifier: protected
// the derived class can access protected members but object can not
// derived class can also have its own members

// polymorphism
// a pointer to derived class is compatible with a pointer to base class
// use virtual function to do it
// pointer/object morph into different type to invoke appropriate function
// Functions can be pure virtual by specifying the = 0
// Classes having at least one pure virtual function are called abstract classes
// and cannot be instantiated. They can only be used as base classes

// Encapsulation
// is grouping the fields into different visibility zones,
// hiding implementation from the user, and exposing the interface

class AbstractClass
{
public:
    virtual void print_class() = 0;
    virtual ~AbstractClass(){};
};
class MyClass
{
private:
    int x;

protected: // protected scope can only be read by derived class, not object
    int z = 7;

public:
    virtual void print_class() // virtual function can be overriden in derived class
    {
        std::cout << "MyClass" << '\n';
    }
};
class MyDerivedClass : public MyClass // create a class derived from a base class
{
public:
    int y;
    void print_protected()
    {
        std::cout << z; // print z, which is in protected scope of base class
    }
    void print_class() // override the function in the base class
    {
        std::cout << "MyDerivedClass" << '\n';
    }
};
int main()
{
    MyDerivedClass derive_obj;
    MyClass *object = new MyDerivedClass; // create an instance of a MyDerivedClass class through a
                                          // base class pointer
    object->print_class();
    derive_obj.print_protected();
    delete object;
}