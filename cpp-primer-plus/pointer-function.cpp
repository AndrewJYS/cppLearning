#include <iostream>
using namespace std;

double funcA (int a) {
    return a * 1.0;
}

void funcPointer(int num, double (* pf)(int)) {
    cout << (* pf)(num) << endl;
}

const double* f1(const double ar[], int n);
const double* f2(const double [], int n);
const double* f3(const double* , int n);

int main() {
    double (* pf)(int);
    pf = funcA;
    cout << funcA(2) << endl;  // output 2
    cout << (* pf)(2) << endl;  // output 2

    funcPointer(2, funcA);  // output 2


    double av[3] = {1.0, 2.0, 3.0};

    const double* (* p1)(const double* , int) = f1;
    auto p2 = f2;
    cout << (* p1)(av, 3) << " " << *(* p1)(av, 3) << endl; // 0x72fde0 1
    cout << (* p2)(av, 3) << " " << *(* p2)(av, 3) << endl; // 0x72fde8 2

    const double* (* pa[3])(const double* , int) = {f1, f2, f3}; //pa是元素为函数指针的数组，即指向数组的指针
    auto pb = pa;
    cout << pa[0](av, 3) << " " << * pa[0](av, 3) << endl; // 0x72fde0 1
    cout << pb[1](av, 3) << " " << * pb[1](av, 3) << endl; // 0x72fde8 2

    auto pc = &pa; //&pa相当于指针的地址
    //*pc解引用，得到指向数组的指针
    cout << (*pc)[0](av, 3) << " " << * (*pc)[0](av, 3) << endl;  // 0x72fde0 1
    const double* (* (*pd)[3])(const double* , int) = &pa;
    cout << (*pd)[1](av, 3) << " " << * (*pd)[1](av, 3) << endl;  // 0x72fdc8 2

    typedef const double* (* pfunc)(const double* , int);
    pfunc pe = f3;
    cout << (* pe)(av, 3) << " " << *(* pe)(av, 3) << endl; // 0x72fdd0 3

    return 0;
}

const double* f1(const double* ar, int n) {
    return ar;
}

const double* f2(const double ar[], int n) {
    return ar + 1;
}
const double* f3(const double ar[], int n) {
    return ar + 2;
}
