

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
  
## 类定义与类实现的分离  
  
分离类的定义和实现有两点好处：隐藏实现，方便维护；保护软件供应商的知识产权  
**注意，'::'称为二元作用域解析运算符，指明了类成员的作用范围，每个构造函数和函数之前的Circle::告知编译器这些函数是定义在Circle类中的  
```c++
//Circle.h
class Circle {
public:
    double radius;
    Circle();
    double getArea();
}; //不要忘记分号

//Circle.cpp
#include "Circle.h"
Circle::Circle() {
    radius = 1;
}
double CirCle::getArea() {
    return radius* radius * 3.14159;
}
```

