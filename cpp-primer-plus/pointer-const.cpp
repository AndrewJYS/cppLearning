#include <iostream>
using namespace std;

void printArray(const int* a, int n) {
    // a[0] = 5; //报错，因为const限定符
}

void test1()
{
    int a[5] = {1,2,3,4,5};
    printArray(a, 5);

    int test = 2;
    const int* b = new int(1);
    //*b = 2;  // b是常量数据因此会报错
    b = &test;
    cout << *b << endl; // output 2

    int* const c = new int(2);
    *c = 6; // c是常量指针
    //c = &test; // 报错

    int* const d = new int(4);
    //int* e = &d; //报错，不能把const指针赋值给非const指针
}

void test2()
{
    char a = 'a';
    char b = 'b';
    char* const pc = &a; //常量指针，不能修改指针的指向
    //pc = &b; // err

    const int* pi = new int{3}; //指针指向的内容不能修改
    //*pi = 5; // err, assignment of read-only location

    const int p[4] = {1,2,3,4};//数组的元素是const，不能修改
    //p[1] = 3; // err
    const int p2[5] = {1,2,3,4,5};
    //p = p2; //err，不可以重新指向新的数组

    const char* c_str1 = "yes"; //可以看作数组元素（字符）是const，不能修改
    //c_str1[1] = 'k'; // err
    c_str1 = "nop!"; //但可以重新指向新的字符串

    char* const c_str2 = "nop"; // 常量指针，不能指向新的字符串
    //c_str2 = "nop2"; // err
    //c_str2[0] = 'j'; // 运行时错误

    char* const pc_array1[] = {"12", "23"};
    //指针数组的元素是char* const，就是说kings1[n]不能指向新的字符串，同char* const c_str2 = "nop"的情形
    //pc_array1[1] = "124"; // err
    //pc_array1[1][0] = 'a'; //运行时错误

    const char* pc_array2[] = {"11", "22"};
    //指针数组的元素是const char*，同const char* c_str1 = "yes"的情形
    // pc_array2[0][1] = 'j'; // err
    pc_array2[0] = "pc_array2"; //OK
}

int main()
{


    return 0;
}
