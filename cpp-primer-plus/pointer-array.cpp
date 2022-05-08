#include <iostream>
using namespace std;

int main(){
    int p1[3];
    cout << p1[0] << endl;

    int * p2 = new int[3];
    cout << p2[0] << endl;

    int* p3[3];
    int num = 3;
    p3[0] = &num;
    cout << p3[0] << endl; // output 0x72fddc

    return 0;
}
