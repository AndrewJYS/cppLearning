# sizeof

sizeof 是一个关键字，它是一个编译时运算符，用于判断变量或数据类型的字节大小，下面是一些示例：  

int  

```c++
int int_num = 1;
cout << sizeof(int_num) << endl;  //output 4
```

double  

```c++
double double_num = 1;
cout << sizeof(double_num) << endl;  //output 8
```

long long  

```c++
long long ll_num = 1;
cout << sizeof(ll_num) << endl;  //output 8
```

struct  

```c++
struct node {
    int int_a;
    double double_b;
    short short_c;
};

node nd;
cout << sizeof(nd) << endl;  //output 24
```

union  

```c++
union one4all {
    int int_val;
    long long ll_val;
    char char_val;
};

one4all oa;
cout << sizeof(oa) << endl; // union的长度为最大成员长度，output 8
```

数组  

对数组应用sizeof得到的是数组的长度，而对指针应用sizeof得到的是指针的长度，即使指针指向的是一个数组  

```c++
int int_array[10];
cout << sizeof(int_array) << endl;  //output 40

int* pa = int_array;
cout << sizeof(pa) << endl;  //output 8
```

字符串  

```c++
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
```

容器  

```c++
vector<short> short_vec(40);
cout << sizeof(short_vec) << endl;  //output 24

vector<double> double_vec(40);
cout << sizeof(double_vec) << endl;  //output 24
```

对象与类  

```c++
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

c class1;
cout << sizeof(class1) << endl;  //output 64

c class2("1234567890");
cout << sizeof(class2) << endl;  //output 64
```

## 参考  

C++ Primer Plus, Chapter 3, 4  
Introduction to Programming with C++, 3rd edition, Chapter 10  
