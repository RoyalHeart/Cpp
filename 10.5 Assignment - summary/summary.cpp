#include <iostream>

// naming convention
// Global: A_Global_Variable
// Class: Capital letter for the first character of each word
// Method: Same with Class but must start with verb
// parameter: first letter lowercase and the rest is like Class
// pointer: add p before the pointer, e.g pInt

// multiple inheritance
// a derived class can be derived from many base class

// virtual inheritance
// when you want only one instance of a base class to pass to derived class
class Human
{
public:
    Human()
    {
        std::cout << "I am a human" << '\n';
    }
};

// if only write class Father : public Human and the same for Mother then the Human class will be called twice
// to fix this we use virtual inheritance
class Father : public virtual Human
{
public:
    Father()
    {
        std::cout << "I am father" << '\n';
    }
};

class Mother : public virtual Human
{

public:
    Mother()
    {
        std::cout << "I am mother" << '\n';
    };
};

class Child : public Father, public Mother
{
public:
    Child()
    {
        std::cout << "I am child" << '\n';
    }
};
void ShowMultipleInheritance()
{
    Father f;
    std::cout << '\n';
    Mother m;
    std::cout << '\n';
    Child c;
}

// copy constructor
// when we use copy constructor for a class that has a pointer
// we need to allocate a new pointer for the new object that is copied from the old object
class Number
{
private:
    int *pInt;

public:
    Number() {}
    Number(int *pInt)
    {
        this->pInt = pInt;
    }
    // copy constructor
    Number(const Number &obj)
    {
        pInt = new int;
        *pInt = *obj.pInt;
    }
    void ChangeInt(int *pInt)
    {
        delete[] pInt;
        *this->pInt = *pInt;
    }
    int Print()
    {
        return *this->pInt;
    }
};

void ShowCopyConstructor()
{
    int a = 9;
    int b;
    int c = 10;
    Number a1(&a);
    Number b1 = a1; //  b1 must have a different pointer

    std::cout << "a1: " << a1.Print() << '\n';
    std::cout << "b1: " << b1.Print() << '\n';

    b1.ChangeInt(&c);
    std::cout << "a1: " << a1.Print() << '\n';
    std::cout << "b1: " << b1.Print() << '\n';
}

// upcasting, downcasting
// upcasting: cast a derived class to base class
// use: when we want to treat derived class as if it is base class
// E.g base class is Instrument, dereived classes are Guitar, Violin, Piano,
// when we want to refer to an instrument just use Instrument instead of individual instrument.

// downcasting: cast a base class to a derived class
// use: when we want to know what is its derived class from a base object array

// void keyword
// void FunctionName(): return nothing
// void parameter: do not need any parameter
// void pointer: can point to any data type, but cannot be dereferenced
void Show(void)
{
    std::cout << "A void funtion" << '\n';
}
void ShowVoid()
{
    Show();
    void *pVoid;
    int a = 8;
    pVoid = &a;
    // std::cout << *pVoid << '\n'; // *pVoid cannot be dereferenced
    int *b = (int *)pVoid; // void pointer must cast to another variable to be dereferenced
    std::cout << *b << '\n';
}

// const
// const variable cannot change its value

class Base
{
private:
    mutable int count = 0; // mutable variable can be changed in const
    int i = 0;

public:
    Base() {}
    int ChangeValue(int aParameter) const // a const member function
    {
        aParameter++;
        return aParameter;
    }
    void ShowValue() const
    {
        count++;                                 // mutable variable can be changed
        std::cout << ChangeValue(count) << '\n'; // the ChangeValue is a const member funtion, therefore it can be used
        std::cout << i << '\n';
    }
};

void ShowConst()
{
    int a = 10;
    const int *pInt = &a; // value of pInt cannot be change
    // (*pInt)++; // *pInt cannot be changed
    a++;                   // however a can be changed
    int *const pInt2 = &a; // address of pInt2 cannot be changed
    std::cout << *pInt << '\n';
    int b = 12;
    // pInt2 = &b; // pInt2 cannot be changed
    *pInt2 = b; // value of pInt2 can be changed
    std::cout << *pInt2 << '\n';
}

int main()
{
    ShowMultipleInheritance();
    std::cout << '\n';
    ShowCopyConstructor();
    std::cout << '\n';
    ShowVoid();
    std::cout << '\n';
    ShowConst();
}
