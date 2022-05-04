#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational r1(4, 2);
    Rational r2(2, 3);
    cout << (operator<(r1, r2)? "true" : "false") << endl;
    cout << ((r1 < r2)? "true" : "false") << endl;

    double d = (double)r2 + 5.1;
    //double d = r2 + 5.1; //会报二义性错误，原因是定义了对象到基本数据类型的转换，也定义了基本数据类型到对象的转换构造函数
    cout << d << endl;


    return 0;
}
