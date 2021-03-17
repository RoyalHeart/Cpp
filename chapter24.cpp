#include <iostream>

class class_1
{
};

class class_2
{
    int i;
    char c;
    bool b;
};

class class_3
{
public:
    void printmessage()
    {
        std::cout << "Hello World" << '\n';
    }
};

class class_4
{
public:
    void printmessage();
};
void class_4::printmessage() // defined function outside of class_4
{
    std::cout << "Hello World" << '\n';
}

class class_5
{
private:
    int i;

public:
    void setx(int myvalue)
    {
        i = myvalue;
    }
    int getx()
    {
        return i;
    }
};

class class_6
{
public:
    class_6();
    ~class_6();
};
class_6::class_6() // constructor
{
    std::cout << "Constructor invoked" << '\n';
}
class_6::~class_6() // destructor
{
    std::cout << "Destructor invoked" << '\n';
}

class class_7
{
private:
    int x;
    double d;

public:
    class_7(int xx, double dd);
    void printdata();
};
class_7::class_7(int xx, double dd) // user-defined constructor
    : x{xx}, d{dd}
{
}
void class_7::printdata()
{
    std::cout << "The value of x: " << x << ", the value of d: " << d << '\n';
}

class class_8
{
private:
    int x;
    double d;

public:
    class_8(int xx, double dd);  // user-provided constructor
    class_8(const class_8 &rhs); // user-defined copy constructor
    void printdata();
};
class_8::class_8(int xx, double dd)
    : x{xx}, d{dd}
{
}
class_8::class_8(const class_8 &rhs)
    : x{rhs.x}, d{rhs.d}
{
}
void class_8::printdata()
{
    std::cout << "X is: " << x << ", d is: " << d << '\n';
}

class class_9
{
private:
    double d;
    std::string s;

public:
    class_9(double dd, std::string ss) // user-provided constructor
        : d{dd}, s{ss}
    {
    }
    class_9(class_9 &&otherobject) // user-defined move constructor
        : d{std::move(otherobject.d)}, s{std::move(otherobject.s)}
    {
        std::cout << "Move constructor invoked." << '\n';
    }
    void printdata()
    {
        std::cout << "The value of the double is: " << d << ", the value of string is : " << s << '\n';
    }
};

class class_10
{
private:
    int x;
    double d;

public:
    class_10(int xx, double dd) // user-provided constructor
        : x{xx}, d{dd}
    {
    }
    void printdata()
    {
        std::cout << "X is: " << x << ", D is: " << d << '\n';
    }
    class_10 &operator-=(const class_10 &rhs) // overload "-=" operator
    {
        this->x -= rhs.x;
        this->d -= rhs.d;
        return *this;
    }
    friend class_10 operator-(class_10 lhs, const class_10 &rhs) // overload "-" operator
    {
        lhs -= rhs;
        return lhs;
    }
};
int main(void)
{
    class_1 a;
    class_2 b;
    class_3 c;
    c.printmessage();
    class_4 d;
    d.printmessage();
    class_5 e;
    e.setx(5);
    std::cout << "The i value is: " << e.getx() << '\n';
    class_6 f;
    class_7 g(7, 7.7);
    g.printdata();
    class_8 h(8, 8.8);
    class_8 h2 = h; // copy constructor
    h.printdata();
    h2.printdata();
    class_9 i(9.9, "Object in class 9");
    class_9 i2 = std::move(i); // move constructor
    i2.printdata();
    class_10 j(10, 10.1);
    class_10 j2(100, 100.11);
    j2 = j - j2; // using overload operator
    j2.printdata();
}
