#ifndef NONPOSITIVESIDEEXCEPTION_H
#define NONPOSITIVESIDEEXCEPTION_H
#include <stdexcept>
using namespace std;

class NonPositiveSideException : public logic_error
{
public:
    NonPositiveSideException(double side): logic_error("Non-positive side")
    {
        this->side = side;
    }

    double getSide() const
    {
        return side;
    }

private:
    double side;
};


#endif // NONPOSITIVESIDEEXCEPTION_H
