#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
    GeometricObject();
    GeometricObject(const string& color, bool filled);
    string getColor() const;
    void setColor(const string& color);
    bool isFilled() const;
    void setFilled(bool filled);
    virtual string toString() const;

private:
    string color;
    bool filled;
};
#endif // GEOMETRICOBJECT_H_INCLUDED
