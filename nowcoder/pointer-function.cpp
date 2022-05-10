#include <iostream>
using namespace std;

class Base {
public:
    Base(int X = 0);
    Base(Base &p);

    static void staticFunc(Base a1, Base a2) {
        cout << a2.X - a1.X << endl;
    }

    void nonstaticFunc(Base a1, Base a2) {
        cout << a2.X - a1.X << endl;
    }

    int X = 0;
    const int i = 1;
    static int j;
};

int Base::j = 2;

Base::Base(int XX) {
    X = XX;
}

Base::Base(Base &p) {
    X = p.X;
}

int main() {
    Base a1(5);
    Base a2(a1);

    void (* q1)(Base,Base) = Base::staticFunc;
    (* q1)(a1, a2);  //output 0

    void (Base::* q2)(Base, Base) = &Base::nonstaticFunc;
    (a1.* q2)(a1, a2);  //output 0

    int (Base::* q3) = &Base::X;
    cout << a1.*q3 << endl;  //output 5

    const int (Base::* q4) = &Base::i;
    cout << a1.*q4 << endl;  //output 1

    int* q5 = &Base::j;
    cout << *q5 << endl;  //output 2

    return 0;
}
