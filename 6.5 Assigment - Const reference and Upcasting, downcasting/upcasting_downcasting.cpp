#include <iostream>
#include <math.h>
#include <tuple>
class Shape
{
public:
    Shape() {}
    virtual void draw() = 0;
    // {
    //     std::cout << "Draw Shape" << '\n';
    // }
    virtual double getArea() = 0;
    virtual void print() = 0;
    void compareArea(Shape *shape)
    {
        if (this->getArea() > shape->getArea())
        {
            std::cout << "Bigger" << '\n';
        }
        else
        {
            std::cout << "Smaller" << '\n';
        }
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle() {}
    Circle(double radius)
    {
        this->radius = radius;
    }
    void draw()
    {
        std::cout << "Draw circle" << '\n';
    }
    double getValue()
    {
        return radius;
    }
    double getArea()
    {
        return M_PI * radius * radius;
    }
    void print()
    {
        std::cout << "Area: " << this->getArea() << '\n';
    }
};
class Square : public Shape
{
private:
    double side;

public:
    Square() {}
    Square(double side)
    {
        this->side = side;
    }
    void draw()
    {
        std::cout << "Draw Square" << '\n';
    }
    double getValue()
    {
        return side;
    }
    double getArea()
    {
        return side * side;
    }
    void print()
    {
        std::cout << "Area: " << this->getArea() << '\n';
    }
};
class Triangle : public Shape
{
private:
    double height;
    double base;

public:
    Triangle() {}
    Triangle(double height, double base)
    {
        this->height = height;
        this->base = base;
    }
    void draw()
    {
        std::cout << "Draw Triangle" << '\n';
    }
    std::tuple<double, double> getValue()
    {
        return std::make_tuple(height, base);
    }
    double getArea()
    {
        return height * base;
    }
    void print()
    {
        std::cout << "Area: " << this->getArea() << '\n';
    }
};

void ex()
{
    Circle c(2);
    Square s(6);
    Triangle t(7, 6);
    // upcasting
    // def: converting a derived-class reference or pointer to a base-class
    // treat a derived type as though it were its base type
    // new derived class is a type of base existing class
    Shape *pShape = &c;
    pShape->compareArea(&s);

    // downcasting
    // def: converting a base-class pointer (reference) to a derived-class pointer (reference)
    // must have explicit type cast (Circle *) because is-a relationship is not, in most of the cases, symmetric
    // derived class can have more data member and function and base class cannot use
    Shape *shape = new Square;
    Circle *pCircle = (Circle *)shape;
    std::cout << "Area: " << pCircle->getArea() << '\n';

    //dynamic casting
    // check if we can safely assign address of object to a pointer of particular
    Shape *shape2 = shape;
    Circle *ptr = dynamic_cast<Circle *>(shape2); // check if shape (Square) can be cast to circle, if yes then return address, no then return null pointer
    // because shape2 is a pointer to Square so it cannot assign
    if (ptr)
    {
        std::cout << "Can assign" << '\n';
    }
    else
    {
        std::cout << "Can't assign" << '\n';
    }
}

int main()
{
    ex();
}