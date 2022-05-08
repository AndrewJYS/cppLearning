#include <iostream>
using namespace std;

int main()
{
    void* p;

    int* a = new int(9);
    double* b = new double(9.2);
    p = &a;
    //cout << *p << endl; //报错
    cout << *((int*)p) << endl; //只是做了转换，并不会输出9
    *((int*)p) = 8;
    //cout << *p << endl; //仍然报错
    cout << *((int*)p) << endl; // output 8

    p = &b;

    return 0;
}
