#include <iostream>
#include <math.h>

class Point
{
private:
    int x;
    int y;

public:
    Point() {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void update(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    double computeDistance(Point object)
    {
        return sqrt(pow((this->x - object.x), 2) + pow((this->y - object.y), 2));
    }
};
class Shape
{
protected:
    Point center;

public:
    Shape() {}
    virtual double computeArea() = 0;
    virtual double computeCircumference() = 0;

    Point getPoint()
    {
        return center;
    }
    double computeDistance(Point object)
    {
        return center.computeDistance(object);
    }
};
class Rectangle : public Shape
{
private:
    double h, w;

public:
    Rectangle() {}
    Rectangle(int x, int y, double h, double w)
    {
        this->center.update(x, y);
        this->h = h;
        this->w = w;
    }
    double computeArea()
    {
        return this->h * this->w;
    }
    double computeCircumference()
    {
        return (this->h + this->w) * 2;
    }
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle() {}
    Circle(int x, int y, double radius)
    {
        this->center.update(x, y);
        this->radius = radius;
    }
    double computeArea()
    {
        return M_PI * this->radius * this->radius;
    }
    double computeCircumference()
    {
        return M_PI * this->radius * 2;
    }
};
class Square : public Shape
{
private:
    double side;

public:
    Square() {}
    Square(int x, int y, double side)
    {
        this->center.update(x, y);
        this->side = side;
    }
    double computeArea()
    {
        return this->side * this->side;
    }
    double computeCircumference()
    {
        return this->side * 4;
    }
};
int main()
{
    Shape *square1 = new Square(3, 3, 5);
    Shape *circle1 = new Circle(4, 4, 5);
    Shape *rectangle1 = new Rectangle(2, 3, 4, 5);
    std::cout << "Area of square: " << square1->computeArea() << '\n';
    std::cout << "Area of circle: " << circle1->computeArea() << '\n';
    std::cout << "Area of rectangle: " << rectangle1->computeArea() << '\n';
    std::cout << "Distance rectangle and circle: " << rectangle1->computeDistance(circle1->getPoint()) << '\n';
    std::cout << "Distance circle and square: " << circle1->computeDistance(square1->getPoint()) << '\n';
    std::cout << "Distance rectangle and square: " << rectangle1->computeDistance(square1->getPoint()) << '\n';
}