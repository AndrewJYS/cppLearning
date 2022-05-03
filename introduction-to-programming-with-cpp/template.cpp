#include <iostream>
using namespace std;

template<class T>
T maxvalue(T value1, T value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

int& mystery()
{
    int z = 5;
    cout << &z << endl;
    return z;
}

int main()
{
    cout << "Maximum between 1 and 3 is " << maxvalue(1, 3) << endl;

    //int z = 5;
    int &p = mystery();
    cout << p << endl;
    cout << &p << endl;
    return 0;
}
