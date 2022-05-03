#include <iostream>
#include "Circle.h"
using namespace std;

void printCircle(Circle& c);
void swap(int& n1, int& n2);
void change(int n);

int main()
{
    Circle* circle1 = new Circle(4.0);
    printCircle(*circle1);
    cout << Circle::getNumberOfObjects() << endl;

    int a = 2;
    int b = 3;
    swap(a, b);
    cout << a << " " << b << endl;

    const int c = 3;
    change(c);

    const int SIZE = 10;
    Circle circeArray[SIZE];
    for (int i = 0; i < 10; i++)
    {
        circeArray[i].setRadius(i + 1);
        cout << circeArray[i].getArea() << " ";
    }

    cout << endl;
    delete circle1;
    cout << Circle::getNumberOfObjects() << endl;

    return 0;
}

void printCircle(Circle& c)
{
    cout << "The area of the circle of " << c.getRadius() << " is " << c.getArea() << endl;
}

void swap(int& n1, int& n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void change(int n)
{
    n++;
    cout << n << endl;
}
