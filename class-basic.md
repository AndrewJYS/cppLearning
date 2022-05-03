

## 声明与定义类  
  
相同类型的对象用一个通用的类来定义。类定义了对象具有什么样的数据域和函数。一个对象就是类的一个实例，创建一个实例称为实例化。  
**注意：**  
**1.如果不使用public关键字，那么这些成员的可见性缺省为private**  
**2.数据域不能在声明时进行初始化**  
```c++
class Circle {
    double area; //不使用public关键字，默认private
private:
    double radius; //不能初始化
};
```
  
## 类定义与类实现的分离，内联函数  
  
分离类的定义和实现有两点好处：隐藏实现，方便维护；保护软件供应商的知识产权  
可以把短函数定义为内联函数提升性能。如果一个函数是在类定义内实现的，则自动成为一个内联函数；或在类实现文件中指明成员函数是内联函数   
**注意：**  
**1.::称为二元作用域解析运算符，指明了类成员的作用范围，每个构造函数和函数之前的Circle::告知编译器这些函数是定义在Circle类中的**  
**2.原语#ifndef，#define(结尾#endif)可以用来避免头文件被多次包含，称之为“包含保护”**  
```c++
//Circle.h  类定义文件
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    double radius;
    Circle();
    double getArea();
    double f1() {//return a number}  //自动成为一个内联函数
    double f2();
}; //不要忘记分号

#endif

//Circle.cpp  类实现文件
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

