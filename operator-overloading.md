# 运算符重载  

**注意：**  
**只有在能使涉及类的代码更易写，尤其时更易读的时候，才使用运算符重载**  

## 确定参数个数  

定义重载的运算符就像定义函数，函数参数表中参数的个数取决于两个因素：  
1.运算符是一元的（一个参数）还是二元的（两个参数）  
2.运算符被定义成全局函数（对于一元是一个参数，对于二元是两个参数）还是成员函数（对于一元没有参数，对于二元是一个参数，此时该类的对象用作左侧参数）  

## 可重载的限制  

不能使用C中当前没有意义的运算符（如**)，不能改变运算符的优先级，不能改变运算符的参数个数。  
不能重载的运算符有：(1) operator.  (2) operator.*  (3)operator?:  (4) operator::  

## 以Rational类为例分析重载运算符  

```c++
class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);
    Rational add(const Rational& secondRational) const;
    double doubleValue() const;

    //define function operators for augmented operators
    Rational& operator+=(const Rational& secondRational);
   
    // define function operator []
    int& operator[](int index);

    //define << and >> operators
    friend ostream& operator<<(ostream&, const Rational&);
    friend istream& operator>>(istream&, Rational&);

private:
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

//具体代码见introduction-to-programming-with-cpp/Rational文件夹
```

### 重载[]运算符  

```c++
int& operator[](int index);
int& Rational::operator[](int index)
{
    if (index == 0)
        return numerator;
    else
        return denominator;
}
```

要将[]运算符函数声明为返回一个引用，否则下述语句会报错  

```c++
Rational r(1,3);
r[0] = 2;
```

### 重载简写，++，--运算符  

左值表示任何可以出现在赋值运算符左侧的内容，右值表示任何可以出现在赋值运算符右侧的内容。我们一般把返回引用的运算符函数称为左值运算符。例如，+=, -=, *=, /=, %=，前缀++，前缀--。

**注意：**  
**1.后缀++，后缀--不是左值运算符**  
**2.前缀++，后缀++的重载区别如下：**  

```c++
Rational& operator++();
Rational operator++(int dummy);
```

左值运算符重载示例如下：  

```c++
Rational& operator+=(const Rational& secondRational);
Rational& Rational::operator+=(const Rational& secondRational)
{
    *this = add(secondRational);
    return *this;
}
```

### 友元函数和友元类  

你可以通过定义友元函数和友元类，使得它能够访问其他类中的私有成员。C++允许重载流插入运算符(<<)和流提取运算符(>>)，这些运算符必须以非成员的友元函数形式出现。示例如下：  

```c++
friend ostream& operator<<(ostream&, const Rational&);
ostream& operator<<(ostream& out, const Rational& rational)
{
    if (rational.denominator == 1)
        out << rational.numerator;
    else
        out << rational.numerator << '/' << rational.denominator;
    return out;
}
```

### 自动类型转换

可以定义函数实现从对象到基本数据类型的自动转换。这是C++中一种定义类型转换函数的特殊语法，函数没有返回类型，函数名就是你期望将对象转换的目标类型。  

**注意：**  
**如果一个类既定义了对象到基本数据类型的转换，也定义了基本数据类型到对象的转换构造函数，则会出现二义性错误**  

```c++
operator double();
Rational::operator double()
{
    return doubleValue();
}
```

## 总结  

拷贝构造函数、赋值运算符和析构函数被称为“三规则”或者“大三元”。如果没有被显式声明，他们将被编译器自动生成。

**注意：**  
**如果类中的一个数据成员是指向动态生成的数组或对象的指针，那么需要修改上述三者中的相应内容，并且，只要修改了其中一个，另两个也要修改。**  

## 参考  

Introduction to Programming with C++, 3rd edition, Chapter 14  
