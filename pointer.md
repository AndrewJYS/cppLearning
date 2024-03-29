
# 指针  

## void 指针  

如果声明指针是void\*，它意味着任何类型的地址都可以间接引用那个指针。一旦间接引用了void*，就会失去关于类型的信息。需要在使用前转换为正确的类型。  

**注意：**  
**一般来说，要避免使用void指针，只有在一些少见的特殊情况下才用**  

```c++
void* p;

int* a = new int(9);
double* b = new double(9.2);

p = &a;
//cout << *p << endl; //报错

cout << *((int*)p) << endl; //只是做了转换，并不会输出9

*((int*)p) = 8;
//cout << *p << endl; //仍然报错
cout << *((int*)p) << endl; // output 8
```

## 数组与指针  

一旦数组声明之后，是不能改变数组地址的。**下面语句非法**  

```c++
int list1[10], list2[10];
list1 = list2; //非法语句

char a[3]; a = "AB"; //同理，也是非法语句 
```

数组名被解释为第一个元素的地址，而对数组名应用地址运算符时，得到的是整个数组的地址。从数字上说，两个地址相同，但从概念上来说，tell是一个2字节内存块的地址，而&tell是一个20字节内存块的地址。因此，tell+1将地址+2;\&tell+2将地址+20。  

```c++
short tell[10];
cout << tell << endl;  //address of first element
cout << &tell << endl; //address of whole array
```

可以用()声明数组元素为默认值（否则元素的值是不确定的），但不能直接初始化为我们想要的某个值  

```c++
int* a = new int[10]();
cout << a[0] << endl; // 0
delete [] a;

string* strs = new string[10]();
cout << strs[0] << endl; // ""
delete [] strs;
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

如果类中没有默认构造函数，那么会报错  

```c++
class Test
{
public:
    Test(int i): r(i){}
private:
    int r;
};

int main()
{
    //Test* t = new Test; // error
    //Test* t = new Test(); // error
    Test* t = new Test(1); // ok
    delete t;
    return 0;
}
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

Thinking in C++, Chapter 3  
C++ Primer Plus, Chapter 7  
Introduction to Programming with C++, 3rd edition, Chapter 11  
