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

数组  

```c++
int int_array[10];
cout << sizeof(int_array) << endl;  //output 40
```

```c++
char* str = "1243523636";
cout << sizeof(str) << endl;  //output 8
cout << sizeof(str[0]) << endl;  //output 1
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

    c() {}

    c(char* str) {
        str_a = str;
    }
};

c class1;
cout << sizeof(class1) << endl;  //output 32

c class2("1234567890");
cout << sizeof(class2) << endl;  //output 32
```

## 参考  

C++ Primer Plus  
Introduction to Programming with C++, 3rd edition, Chapter 10  
