
# 指针  

## 数组与指针  

一旦数组声明之后，是不能改变数组地址的。**下面语句非法**  

```c++
int list1[10], list2[10];
list1 = list2; //非法语句

char a[3]; a = "AB"; //同理，也是非法语句 
```

## 指针数组  

声明指针数组：DataType* p[n];

```c++
int* p3[3];
int num = 3;
p3[0] = &num;
cout << p3[0] << endl; // output 0x72fddc
```

区别于数组指针：  

```c++
int* p2 = new int[3];
cout << p2[0] << endl;
```

## 函数指针  

函数的地址是存储其机器语言代码的内存的开始地址。假设函数原型如下：  

```c++
doule pam(int);
```

则正确的指针声明如下：  

```c++
double (* pf)(int);
```

也就是说，声明应指定函数的返回类型和参数列表。具体实例如下：  

```c++
double funcA (int a) {
    return a * 1.0;
}

void funcPointer(int num, double (* pf)(int)) {
    cout << (* pf)(num) << endl;
}


int main() {
    double (* pf)(int);
    pf = funcA;
    cout << funcA(2) << endl;  // output 2
    cout << (* pf)(2) << endl;  // output 2

    funcPointer(2, funcA);  // output 2

    return 0;
}
```

一个更复杂的示例如下：  

```c++
const double* f1(const double ar[], int n);
const double* f2(const double [], int n);
const double* f3(const double* , int n);

const double* f1(const double* ar, int n) {
    return ar;
}

const double* f2(const double ar[], int n) {
    return ar + 1;
}
const double* f3(const double ar[], int n) {
    return ar + 2;
}

int main() {
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
}
```

也可以使用typedef简化语句，下述示例承接上例的定义  

```c++
typedef const double* (* pfunc)(const double* , int);
pfunc pe = f3;
cout << (* pe)(av, 3) << " " << *(* pe)(av, 3) << endl; // 0x72fdd0 3
```

## 动态内存持久分配  

new操作符可以在运行时为基本数据类型、数组和对象分配持久的内存空间。C++中，局部变量在栈中分配空间，new操作符分配的内存空间出自于自由存储区或者堆的内存区域。new操作符创建的数组称为动态数组。  

```c++
int* list = new int[4];
```

**注意：**  
**当创建普通数组时，其大小会在编译时确定，因此不能是变量，必须是常量；当创建动态数组时，数组大小是运行时确定的，可以是整型变量。使用new操作符分配的内存是持久存在的，直到被显式地释放或者程序推出**  

```c++
int nums[20];
int* nums = new int[size];
```

如果内存是为数组分配的，则使用下述语句释放空间  

```C++
delete [] list; //list为数组
```

## 创建及访问动态对象  

调用对象的构造函数可以动态地创建对象  

```c++
//使用无参构造函数创建对象
ClassName* pObject = new ClassName();
ClassName* pObject = new ClassName;

//使用有参构造函数创建对象
ClassName* pObject = new ClassName(arguments);
```

**注意：**  
**通过指针访问所指向的对象的成员，需要先解引用指针，然后用点操作符访问**  

```c++
ClassName* pObject = new ClassName();
(*pObject).func();
```

C++提供了一个成员选择操作符，可以简化通过指针来访问对象成员  

```c++
ClassName* pObject = new ClassName();
pObject->func();
```

使用delete关键字销毁对象  

```c++
ClassName* pObject = new ClassName;
delete pObject;
```

## this指针  

this指针指向被调用的对象本身  

## 析构函数  

每个类都有一个析构函数，当一个对象销毁时将自动调用该析构函数。如果没有显式定义析构函数，那么编译器会为每个类定义一个缺省的析构函数。  

**注意：**  
**当类中包含指针数据域，而该指针指向动态分配的内存时，应使用自定义的析构函数，不然，使用该类的程序会发生内存泄漏**  

## 拷贝构造函数  

缺省的拷贝构造函数和赋值运算符进行对象复制会采用“浅拷贝”的方式。如果数据域是一个指向其他对象的指针，那么浅拷贝只会简单复制指针保存的地址值，而不会复制指向的对象的内容。可以自定义拷贝构造函数，实现深拷贝。

**注意：**  
**若类中包含指针数据域，该指针指向动态分配的内存，且类中包含销毁析构函数。如果生成了两个对象，当程序退出时，会调用析构函数两次，来删除堆上分配的内容。由于两个对象的指针数据域指向相同的地址，内容会被删除两次，程序会报错**  

## 参考  

C++ Primer Plus, Chapter 7  
Introduction to Programming with C++, 3rd edition, Chapter 11  
