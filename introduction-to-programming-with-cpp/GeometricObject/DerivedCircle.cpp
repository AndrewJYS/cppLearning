#include "DerivedCircle.h"

Circle::Circle()
{
    radius = 1;
}

Circle::Circle(double radius)
{
    this->radius = radius;
}

Circle::Circle(double radius, const string& color, bool filled)
{
    setRadius(radius);
    setColor(color);
    setFilled(filled);
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}

double Circle::getArea() const
{
    return radius * radius * 3.14159;
}

double Circle::getPerimeter() const
{
    return 2 * radius * 3.14159;
}

double Circle::getDiameter() const
{
    return 2 * radius;
}

string Circle::toString() const
{
    return "Circle Object";
}
