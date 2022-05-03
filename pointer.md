
## 常量指针  

常量指针指向一个不变的内存位置，但该内存位置的实际值时可以改变的。下述语句中第一个const表示常量数据，第二个const表示常量指针。  

```c++
const double* const pvalue = &radius;
```

## 数组与指针  

一旦数组声明之后，是不能改变数组地址的。**下面语句非法**  

```c++
int list1[10], list2[10];
list1 = list2; //非法语句
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
