#include <iostream>
#include <vector>
using namespace std;

struct node {
    int int_a;
    double double_b;
    short short_c;
};

class c {
public:
    char* str_a;
    double double_b;
    short short_c;
    long long ll_d;

    c() {}

    c(char* str) {
        str_a = str;
    }
};

int main()
{
    int int_num = 1;
    cout << sizeof(int_num) << endl;  //output 4

    double double_num = 1;
    cout << sizeof(double_num) << endl;  //output 8

    long long ll_num = 1;
    cout << sizeof(ll_num) << endl;  //output 8

    node nd;
    cout << sizeof(nd) << endl;  //output 24

    int int_array[10];
    cout << sizeof(int_array) << endl;  //output 40

    char* str = "1243523636";
    cout << sizeof(str) << endl;  //output 8
    cout << sizeof(str[0]) << endl;  //output 1

    vector<short> short_vec(40);
    cout << sizeof(short_vec) << endl;  //output 24

    vector<double> double_vec(40);
    cout << sizeof(double_vec) << endl;  //output 24

    c class1;
    cout << sizeof(class1) << endl;  //output 32

    c class2("1234567890");
    cout << sizeof(class2) << endl;  //output 32

    return 0;
}
