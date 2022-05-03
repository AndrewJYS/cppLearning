#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational r1(4, 2);
    Rational r2(2, 3);
    cout << (operator<(r1, r2)? "true" : "false") << endl;
    cout << ((r1 < r2)? "true" : "false") << endl;



    return 0;
}
