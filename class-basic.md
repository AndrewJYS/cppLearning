# 类  

## 概述

采用OOP方法时，首先从用户的角度去考虑对象——描述对象所需的数据以及描述用户与数据交互所需要的操作。完成对接口的描述后，需要确定如何实现接口和数据存储。最后设计程序。  
  
## 接口  

接口是一个共享框架，供两个系统交互时使用。对于类，接口规定我们能向特定的对象发出什么请求；接口由编写类的人提供的方法组成。接口让程序员可以编写与类对象交互的代码。  
  
## 声明与定义类  
  
相同类型的对象用一个通用的类来定义。类定义了对象具有什么样的数据域和函数。一个对象就是类的一个实例，创建一个实例称为实例化。  
使用private关键字，将数据域声明为私有，这就是所谓的数据域封装。这样，在类之外的程序中，无法直接引用类对象来访问该数据域。  
  
**注意：**  
**1.如果不使用public关键字，那么这些成员的可见性缺省为private（结构的默认访问类型是public，类的默认访问类型是private）**  
**2.数据域不能在声明时进行初始化**  

```c++
class Circle {
    double area; //不使用public关键字，默认private
private:
    double radius; //不能初始化
};
```

## 构造函数  

若用户没有编写非默认构造函数，C++会自动提供默认的无参构造函数。一旦用户编写了非默认构造函数，默认的无参构造函数消失。如果用户还希望有一个无参构造函数，必须自行编写。例如有Stock类，用户定义了非默认构造函数，但是没有定义默认构造函数，则使用下述语句创建对象会报错  

```c++
Stock stock;//error
```

## 创建对象  

使用**无参构造函数**创建对象的语法如下：  

```c++
ClassName objectName;

ClassName* pObject = new ClassName;
ClassName* pObject = new ClassName();
```

使用带参数的构造函数创建对象的语法如下：  

```c++
ClassName objectName(arguments);

ClassName* pObject = new ClassName(arguments);
```
  
## 类定义与类实现的分离，内联函数  
  
分离类的定义和实现有两点好处：隐藏实现，方便维护；保护软件供应商的知识产权。  
可以把短函数定义为内联函数提升性能。如果一个函数是在类定义内实现的，则自动成为一个内联函数；或在类实现文件中指明成员函数是内联函数。  
**注意：**  
**1.::称为二元作用域解析运算符，指明了类成员的作用范围，每个构造函数和函数之前的Circle::告知编译器这些函数是定义在Circle类中的**  
**2.原语#ifndef，#define(结尾#endif)可以用来避免头文件被多次包含，称之为“包含保护”**  
**3.长函数不适于定义成内联函数**  
  
Circle.h  类定义文件  

```c++
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    double radius;
    Circle();
    double getArea();
    double f1() {//return a number}  //自动成为一个内联函数
    double f2();
}; //不要忘记分号

#endif
```
  
Circle.cpp  类实现文件  

```c++
#include "Circle.h"
Circle::Circle() {
    radius = 1;
}

double CirCle::getArea() {
    return radius* radius * 3.14159;
}

inline double Circle::f2() { //在函数头前使用关键字inline，声明为内联函数
    //return a number
}
```
  
## 变量作用域  
  
一个全局变量的作用域从它的声明位置开始，直至程序结束。  
局部变量定义在函数内，其作用域从它的声明位置开始， 直至包含他的程序块结束。  
静态局部变量在程序中的存储空间是持久的，因此在下次函数调用时仍可以访问。  
**注意：**  
**如果成员函数中一个局部变量和一个数据域具有相同的名字，数据域会被屏蔽，因为局部变量的优先级更高**  

```c++
class Foo {
public:
    int x;
    int y;
      
    Foo() {
        x = 10;
        y = 10;
    }
    
    void p() {
        int x = 20;
        cout << x << " " << y << endl;
    }
};

int main() {
    Foo foo;
    foo.p(); //输出20，10
    return 0;
}
```
  
## 实例成员，静态成员，只读成员函数  
  
如果希望一个类的所有实例共享数据，就应该使用静态变量。静态变量机制在一个共同的内存位置保存多个对象的变量的值。C++也支持静态函数，调用静态函数无须创建一个类实例，而实例函数只可以通过特定实例来调用。
  
只读成员函数需加上const关键字，这样编译器知道该函数不会改变对象的数据域。和常量参数一样，只读函数也是一种防御式编程。  
  
**注意：**  
**1.声明静态成员，需要添加static修饰符，若在类定义文件中使用了static，类实现文件中可以省略static**  
**2.只有实例函数可以被定义为只读函数，静态函数不能被定义为只读函数**  
  
## 对象数组  

```c++
Circle array[10];  
```

这条语句创建了包含10个Circle对象的数组，且调用无参的构造函数，初始化数组中的每个元素  

```c++
Circle array[3] = {Circle(1), Circle(2), Circle(3)};  
```

该语句用数组初始化语句声明对象数组，且通过有参构造函数初始化对象数组元素  
  
## 参考  

Introduction to Programming with C++, 3rd edition, Chapter 9, 10, 11  
C++ Primer Plus, 6th edition, Chapter 10  
