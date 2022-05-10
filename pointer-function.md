# 函数指针  

## 定义  

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

## 类成员函数的指针  

静态成员函数指针：  

```c++
returnType (* p)(arguments) = ClassName::FunctionName;
(* p)(arguments);
```

非静态成员函数指针：  

```c++
ClassName object;
returnType(ClassName::* p) = &ClassName::FunctionName;
(object.* p)(arguments);
```

示例如下：  

```c++
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
```

## 参考  

C++ Primer Plus, Chapter 7  
https://www.nowcoder.com/test/question/done?tid=56239302&qid=51829#summary  
