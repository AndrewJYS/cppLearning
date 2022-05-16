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
    string ss;

    c() {}

    c(char* str) {
        str_a = str;
    }
};

union one4all {
    int int_val;
    long long ll_val;
    char char_val;
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

    one4all oa;
    cout << sizeof(oa) << endl; // output 8

    int int_array[10];
    cout << sizeof(int_array) << endl;  //output 40
    int* pa = int_array;
    cout << sizeof(pa) << endl;  //output 8

    string str1 = "1243523636";
    cout << sizeof(str1) << endl;  //output 32

    char str2[21] = "1243523636";
    cout << sizeof(str2) << endl;  //output 21
    cout << int(str2[15]) << endl;  // output 0

    char str3[] = "1243523636";
    cout << sizeof(str3) << endl;  //output 11

    char* str4 = "1243523636";
    cout << sizeof(str4) << endl;  //output 8
    cout << sizeof(str4[0]) << endl;  //output 1

    vector<short> short_vec(40);
    cout << sizeof(short_vec) << endl;  //output 24

    vector<double> double_vec(40);
    cout << sizeof(double_vec) << endl;  //output 24

    c class1;
    cout << sizeof(class1) << endl;  //output 64

    c class2("1234567890");
    cout << sizeof(class2) << endl;  //output 64

    return 0;
}
