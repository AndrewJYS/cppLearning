#include <iostream>
using namespace std;

union one4all {
    int int_val;
    long long ll_val;
    char char_val;
};

int main()
{
    one4all oa;
    oa.int_val = 6;
    cout << oa.int_val << endl; // output 6

    oa.ll_val = 5000;
    cout << oa.ll_val << endl; // output 5000

    cout << oa.int_val << endl; // output 5000

    return 0;
}
