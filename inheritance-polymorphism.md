# 继承与多态  

面向对象编程的三大支柱是封装性，继承性和多态性  

## 继承  

面向对象程序设计允许从已有类派生出新的类，这称为继承。一个类定义了一种类型，被派生类定义的类型称为子类型；被基类定义的类型称为超类型。  

## 基类和派生类  

派生类继承了其基类的所有**可访问**的数据域和函数，同时可以增加新的数据域和函数。下面代码中，Circle类不能直接访问基类的color和filled  

```c++
class GeometricObject {
    ...
private:
    string color;
    bool filled;
};

class Circle: public GeometricObject {
    ...
private:
    double radius;
}
```

C++允许同时扩展多个类来得到一个派生类，该功能被称为多重继承  

## 构造函数和析构函数  

派生类并不继承基类的构造函数。派生类仅仅在自己的构造函数中调用基类的构造函数，来初始化基类的数据域。派生类的构造函数在执行其自身代码前首先调用它的基类的构造函数；派生类的析构函数首先执行其自身的代码，然后自动调用其基类的析构函数。  

**注意：**  
**如果考虑一个类可能被继承，那么最好为其设计一个无参构造函数，避免程序错误**  

## 重定义函数

重载一个函数是为了提供多个名字相同但签名不同的函数；重定义一个函数，必须在派生类中定义一个与基类函数具有相同签名和返回类型的函数。  

## 多态，虚函数，动态绑定  

多态意味着一个超类型的变量可以引用一个子类型的对象。下述代码可以正常运行，但输出内容均为基类GeometricObject中定义的toString()函数。  

```c++
class GeometricObject{
...
    string toString() const;
};

class Circle: public GeometricObject{
...
    string toString() const;
};

class Rectangle: public GeometricObject{
...
    string toString() const;
};

void displayGeometricObject(const GeometricObject& g) {
    cout << g.toString() << endl;
}

int main() {
    GeometricObject shape;
    displayGeometricObject(shape);

    Circle circle(5);
    displayGeometricObject(circle);

    Rectangle rectangle(2, 3);
    displayGeometricObject(rectangle);

    ...
}
```

将基类toString()添加virtual修饰符，即可分别调用对象各自定义的toString()函数了。此时C++动态决定应该调用哪个toString()函数，这种在运行时判断调用哪个函数的功能称为动态绑定。我们把含有虚函数的类称为多态类型。  

**注意：**  
**1.为使一个函数能够动态绑定，要做两件事：(1)在基类中，函数必须声明为虚函数。(2)在虚函数中，引用对象的变量必须以引用或指针的形式传递**  
**2.如果一个函数在基类中定义为虚函数，在派生类中，自然也是虚函数，不必在派生类中的函数声明中添加virtual关键字**  
**3.如果一个函数不会被重定义，则不要声明为虚函数，因为在运行时动态绑定虚函数会花费更多的时间和系统资源**  

```c++
class Circle: public GeometricObject
{
...
    virtual string toString() const;
};
```

## 关键字protected  

私有成员只能被类内或友元函数和友元类访问  
公有成员可以被任意其他类访问  
一个类的保护成员可以被派生类访问  

下面是一个示例，注意Base构造函数权限为protected，在类外除了继承的方式，无法实例化对象，因此Base a;语句会报错。  

```c++
class Base {
public:
    void f(){cout<<"Base::f()"<<endl;}
protected:
    Base(){cout<<"Base::Base"<<endl;}
private:
    void g() {cout<<"Base::g()"<<endl;}
}
 
class First: public Base{
public:
    First(){cout<<"First::First"<<endl;}
}

Base a; //报错
```

## 抽象类和纯虚函数  

抽象函数被称为纯虚函数，包含纯虚函数的类称为抽象类。一个抽象函数的定义方式如下，其中 **= 0** 指明该函数是纯虚函数。  

```c++
virtual double getArea() = 0;
```

**注意：**  
**1.抽象类不能用来创建对象**  
**2.在基类中，纯虚函数没有函数体或实现。这些抽象函数在具体的派生类中实现**  
**3.设基类是抽象类，若子类也是抽象类，并不要求一定重写基类抽象函数；如果子类不是抽象类，则一定要重写基类抽象函数**  

## 类型转换  

将一个派生类指针赋值成以一个基类指针，称为向上转型，反之称为向下转型。

**注意：**  
**1.对于向上转型，可以不使用static_cast,dynamic_cast运算符，来隐式转换。但是，向下转型必须显式执行**  
**2.dynamic_cast只能在类型的指针或引用上使用，也就是说，该类型必须包含虚函数。dynamic_cast可以在运行时检查强制转换是否成功，static_cast则在编译时起作用。**  

```c++
GeometricObject* p = new Circle(1);
Circle* p1 = new Circle(2);
p = p1;   // p1向上转型
```

```C++
GeometricObjec* p = new Circle(1);
Circle* p1 = new Circle(2);
p1 = static_cast<Circle*>(p); //p向下转型
p1 = dynamic_cast<Circle*>(p);
```

## 参考  

Introduction to Programming with C++, 3rd edition, Chapter 15  
