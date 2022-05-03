#include <iostream>
#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
using namespace std;

void displayGeometricObject(GeometricObject& g)
{
    cout << "The area is " << g.getArea() << endl;
    cout << "The Perimeter is " << g.getPerimeter() << endl;

    GeometricObject* p = &g;
    Circle* p1 = dynamic_cast<Circle*>(p);
    Rectangle* p2 = dynamic_cast<Rectangle*>(p);

    if (p1 != NULL)
    {
        cout << "The radius is " << p1->getRadius() << endl;
        cout << "The diameter is " << p1->getDiameter() << endl;
    }

    if (p2 != NULL)
    {
        cout << "The width is " << p2->getWidth() << endl;
        cout << "The height is " << p2->getHeight() << endl;
    }
}

int main()
{
    Circle circle(5);
    Rectangle rectangle(5, 3);

    cout << "Circle info: " << endl;
    displayGeometricObject(circle);

    cout << "Rectangle info: " << endl;
    displayGeometricObject(rectangle);

    return 0;
}
