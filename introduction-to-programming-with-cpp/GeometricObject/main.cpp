#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

void displayGeometricObject(const GeometricObject& g)
{
    cout << g.toString() << endl;
}

void testGeometricObject()
{
    GeometricObject shape;
    shape.setColor("red");
    shape.setFilled(true);
    cout << shape.toString() << endl << shape.getColor() << " " << shape.isFilled() << endl;

    Circle circle(5);
    circle.setColor("black");
    circle.setFilled(false);
    cout << circle.toString() << endl << circle.getColor() << " " << circle.isFilled() <<
        " " << circle.getRadius() << " " << circle.getArea() << " " << circle.getPerimeter() << endl;

    Rectangle rectangle(2, 3);
    rectangle.setColor("orange");
    rectangle.setFilled(true);
    cout << rectangle.toString() << endl << rectangle.getColor() << " " << rectangle.isFilled() <<
        " " << rectangle.getWidth() << " " << rectangle.getArea() << " " << rectangle.getPerimeter() << endl;

    displayGeometricObject(shape);
    displayGeometricObject(circle);
    displayGeometricObject(rectangle);
}

void testTriangle()
{
    try
    {
        Triangle triangle(-1, 3, 4);
        cout << triangle.getArea() << endl;
        cout << triangle.getPerimeter() << endl;

        triangle.setSide1(3);
        cout << triangle.getArea() << endl;
        cout << triangle.getPerimeter() << endl;
    }
    catch(TriangleException& ex)
    {
        cout << ex.what() <<endl;
    }
    catch(NonPositiveSideException& ex)
    {
        cout << ex.what() << endl;
    }
    catch(...)
    {
        cout << "Handle all other exceptions" << endl;
    }
}

int main()
{
    testGeometricObject();

    testTriangle();

    return 0;
}
