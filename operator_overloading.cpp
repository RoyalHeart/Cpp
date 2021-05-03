#include <iostream>
#include <vector>

// function overloading
// functions can be used with same name but different type of arguments(parameters)
void print_element(int a)
{
    std::cout << "integer is: " << a << '\n';
}
void print_element(char a)
{
    std::cout << "character is: " << a << '\n';
}
void function_overloading()
{
    std::cout << "Function overloading:" << '\n';
    int a = 5;
    char b = 'c';
    print_element(a);
    print_element(b);
}

// operator overloading
// most operator can be overload, except: (::, .*, ., ?:)
class Box
{
private:
    double length;
    double breadth; // depth
    double height;
    double arr[3];

public:
    Box() {}
    Box(double length, double breadth, double height)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
        this->arr[0] = length;
        this->arr[1] = breadth;
        this->arr[2] = height;
    }
    double getVolume(void)
    {
        return length * breadth * height;
    }
    void setLength(double len)
    {
        length = len;
    }
    void setBreadth(double bre)
    {
        breadth = bre;
    }
    void setHeight(double hei)
    {
        height = hei;
    }
    void setRandom()
    {
        length = rand() % 10;
        breadth = rand() % 10;
        height = rand() % 10;
    }

    // overload + operator to add two Box objects and return a new box
    // this is also a binary operator overloading
    Box operator+(const Box &b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

    // overload - operator (negative)
    Box operator-()
    {
        length = -length;
        breadth = -breadth;
        height = -height;
        return Box(length, breadth, height);
    }

    // overload - operator (subtraction)
    Box operator-(const Box &b)
    {
        Box box;
        box.length = this->length - b.length;
        box.breadth = this->breadth - b.breadth;
        box.height = this->height - b.height;
        return box;
    }

    // overload > operator
    bool operator>(Box &b)
    {
        if (this->getVolume() > b.getVolume())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // input/output operator overloading
    friend std::ostream &operator<<(std::ostream &output, const Box &b)
    {
        output << "Length: " << b.length << " Breadth: " << b.breadth << " Height: " << b.height;
        return output;
    }

    friend std::istream &operator>>(std::istream &input, Box &b)
    {
        input >> b.length >> b.breadth >> b.height;
        return input;
    }

    // assignment operator overloading
    void operator=(const Box &b)
    {
        length = b.length;
        breadth = b.breadth;
        height = b.height;
    }

    // function call operator overloading
    Box operator()(int a, int b, int c, int d)
    {
        Box box;
        box.length = a + d;
        box.breadth = b + d;
        box.height = c + d;
        return box;
    }

    // subscripting [] operator overloading
    double &operator[](int i)
    {
        if (i > 3)
        {
            std::cout << "Index out of bounds" << '\n';
            // return first element.
            return arr[0];
        }

        return arr[i];
    }
};
class ObjContainer
{
    std::vector<Box *> a;

public:
    void add(Box *obj)
    {
        a.push_back(obj); // call vector's standard method.
    }
    friend class SmartPointer;
};

// implement smart pointer to access member of Obj class.
class SmartPointer
{
    ObjContainer oc;
    int index;

public:
    SmartPointer(ObjContainer &objc)
    {
        oc = objc;
        index = 0;
    }

    // Return value indicates end of list:
    bool operator++()
    { // Prefix version
        if (index >= oc.a.size())
            return false;
        if (oc.a[++index] == 0)
            return false;
        return true;
    }

    bool operator++(int)
    { // Postfix version
        return operator++();
    }

    // class member access operator (->) overloading
    // it is defined to give a class type a "pointer-like" behavior
    Box *operator->() const
    {
        if (!oc.a[index])
        {
            std::cout << "Zero value";
            return (Box *)0;
        }

        return oc.a[index];
    }
};

// example of operator overloading
// + operator is a binary operator

void operator_overloading()
{
    std::cout << '\n'
              << "Example of operator overloading:" << '\n';
    Box b1(1, 2, 3);
    Box b2(4, 5, 6);
    Box b3;
    // overload '+' operator
    b3 = b1 + b2; // b3(5,7,9)
    double volumn1 = b1.getVolume();
    double volumn2 = b2.getVolume();
    double volumn3 = b3.getVolume();
    std::cout << "volumn of box 1 is: " << volumn1 << '\n';
    std::cout << "volumn of box 2 is: " << volumn2 << '\n';
    std::cout << "volumn of box 3 is: " << volumn3 << '\n';
}

// unary operator overloading
// unary operator is operator that only need a single operand
// e.g. ++, --, -, !
void unary_operator_oveloading()
{
    std::cout << '\n'
              << "Unary operator overloading:" << '\n';
    Box b1(1, 2, 3);
    double volumn = -b1.getVolume();
    std::cout << "Box 1 negative volumn is: " << volumn << '\n';
}

// binary operator overloading
// binary oprator need two operands
// e.g. +, -(subtraction) , /
void binary_operator_oveloading()
{
    std::cout << '\n'
              << "Binary operator oveloading:" << '\n';
    Box b1(1, 2, 3);
    Box b2(4, 5, 6);
    Box b3;
    // overload '+' operator
    b3 = b2 - b1; // b3(3,3,3)
    double volumn1 = b1.getVolume();
    double volumn2 = b2.getVolume();
    double volumn3 = b3.getVolume();
    std::cout << "volumn of box 1 is: " << volumn1 << '\n';
    std::cout << "volumn of box 2 is: " << volumn2 << '\n';
    std::cout << "volumn of box 3 is: " << volumn3 << '\n';
}

// relational operator overloading
// e.g. >, <, >=, <=, ==, etc
void relational_operator_overloading()
{
    std::cout << '\n'
              << "Relational operator overloading:" << '\n';
    Box b1(1, 2, 3);
    Box b2(4, 5, 6);
    if (b1 > b2)
    {
        std::cout << "Box 1 has bigger volumn than box 2" << '\n';
    }
    else
    {
        std::cout << "Box 2 has bigger volumn than box 1" << '\n';
    }
}

// input/output operators overloading
// e.g. cout <<, cin >>
void input_output_operator_overloading()
{
    std::cout << '\n'
              << "Input/Output operator overloading: " << '\n';
    Box b1(1, 2, 3);
    Box b2(4, 5, 6);
    std::cout << b1 << '\n';
    std::cin >> b2;
    std::cout << b2 << '\n';
}

// assignment operators overloading
// e.g =
// like a copy constructor
void assignment_operator_overloading()
{
    std::cout << '\n'
              << "Assignment operator overloading: " << '\n';
    Box b1(1, 2, 3);
    Box b2;
    b2 = b1;
    double volumn = b2.getVolume();
    std::cout << "Box 1 volumn is : " << volumn << '\n';
}

// function call operator overloading
void funciton_call_operator_overloading()
{
    std::cout << '\n'
              << "Function call operator overloading:" << '\n';
    Box b1(1, 2, 3), b2;
    std::cout << "Box 1 volumn: " << b1.getVolume() << '\n';
    b2 = b1(1, 2, 3, 1); // b2(2,3,4)
    std::cout << "Box 2 volumn: " << b2.getVolume() << '\n';
}

// subcripting [] operator overloading
// we can use index to access to a properties of class object
void subcripting_operator_overloading()
{
    std::cout << '\n'
              << "Subcripting operator overloading" << '\n';
    Box b1(1, 2, 3);
    std::cout << "Box 1 has lenght: " << b1[0] << '\n';
    std::cout << "Box 1 has breath: " << b1[1] << '\n';
    std::cout << "Box 1 has height: " << b1[2] << '\n';
}

// class member access operator overloading
void class_member_access_operator_overloading()
{
    std::cout << '\n'
              << "Class member access operator overloading" << '\n';
    int size = 10;
    Box b[size];
    ObjContainer oc;
    // add all obj to container
    for (int i = 0; i < size; i++)
    {
        oc.add(&b[i]);
    }
    SmartPointer sp(oc); // Create an iterator
    do
    {
        sp->setRandom();                                    // set length, breadth and height randomly from 0 to 10
        std::cout << "Volumn: " << sp->getVolume() << '\n'; // smart pointer call
    } while (sp++);
}
int main()
{
    function_overloading();
    operator_overloading();
    unary_operator_oveloading();
    binary_operator_oveloading();
    relational_operator_overloading();
    input_output_operator_overloading();
    assignment_operator_overloading();
    funciton_call_operator_overloading();
    subcripting_operator_overloading();
    class_member_access_operator_overloading();
}