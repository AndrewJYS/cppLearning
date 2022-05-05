# 异常处理  

## 模板  

try-throw-catch模板如下，异常可以通过try块中的throw语句直接抛出，也可以是从一个可能抛出异常的函数中产生。  

```c++
try {
    code to try;
    Throw an exception with a throw statement or from function if necessary;
    more code to try;
}
catch (type ex) {
    code to process the exception;
}
```

如果对异常对象的内容不感兴趣，那么可以忽略catch块的参数  

```c++
```c++
try {
    ...
}
catch (int) {
    cout << "Error occurred" << endl;
}
```

## 自定义异常类  

异常类和其他C++类没有差别，但通常应该派生自exception类，或exception类的某个派生类，这样你就可以利用exception类中的一些公共特性。示例如下：  

```c++
class TriangleException: public logic_error{
public:
    TriangleException(double side1, double side2, double side3): logic_error("Invalid triangle")
    {
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }

    ...
};

class Triangle : public GeometricObject{
public:
    Triangle(double side1, double side2, double side3) throw (TriangleException)
    {
        if (!isValid(side1, side2, side3))
            throw TriangleException(side1, side2, side3);

        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }
    ...

    bool isValid(double side1, double side2, double side3) const {
        return (side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2);
    }

};

//具体代码见introduction-to-programming-with-cpp/GeometricObject文件夹
```

## 多重异常捕获  

一个try-catch模块可能包含多个catch语句，用于处理try语句抛出的各种异常类型。  

**注意：**  
**基类对应的catch模块应放置在派生类的catch模块之后。否则，派生类类型的异常总是会被基类类型的catch模块所捕获。**  

```c++
class NonPositiveSideException : public logic_error {
public:
    NonPositiveSideException(double side): logic_error("Non-positive side") {
        this->side = side;
    }
    ...
};

class Triangle : public GeometricObject {
public:
    Triangle(double side1, double side2, double side3) throw (NonPositiveSideException, TriangleException)
    {
        check(side1);
        ...
        if (!isValid(side1, side2, side3))
            throw TriangleException(side1, side2, side3);
        ...
    }
    ...

    bool isValid(double side1, double side2, double side3) const {
        return (side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2);
    }

    void check(double side) const throw (NonPositiveSideException) {
        if (side <= 0)
            throw NonPositiveSideException(side);
    }
};

int main() {
    try {...}
    catch (NonPositiveSideException& ex) {...}
    catch (TriangleException& ex) {...}
    ...
}

//具体代码见introduction-to-programming-with-cpp/GeometricObject文件夹
```

可以使用...作为catch的参数，将会使得这个catch模块捕获所有类型的异常。  

```c++
try {
    ...
}
catch (Exception1& ex1) {
    ...
}
catch (Exception2& ex2) {
    ...
}
catch (...) {//捕获所有异常
    ...
}
```

## 异常的传播  

一个异常会通过一条函数调用链被不断抛出，直到被捕获或是到达main函数。例如，下述程序如果输入0，则会输出  
logic error  
statement 4  
statement 1  
statement 2  
原因是function3()抛出的异常不能被function2()中处理，需要返回给function1()处理。  

```c++
int main() {
    try {
        function1();
        cout << "statement 1" << endl;
    }
    catch(runtime_error) {
        cout << "runtime error" << endl;
    }
    cout << "statement 2" << endl;

    return 0;
}

void function1() {
    try {
        function2();
        cout << "statement 3" << endl;
    }
    catch(logic_error) {
        cout << "logic error" << endl;
    }
    cout << "statement 4" << endl;
}

void function2() {
    try {
        function3();
        cout << "statement 5" << endl;
    }
    catch(bad_alloc) {
        cout << "bad allocation" << endl;
    }
    cout << "statement 6" << endl;
}

void function3() {
    int num;
    cin >> num;
    if (num == 0)
        throw logic_error("zero");
}
```

## 异常说明  

异常说明的语法如下：  

```c++
returnType functionName(parameterList) throw (exceptionList);
```

**注意：**  
**将throw()放在函数头后，称为空异常说明，表示函数不能抛出任何异常。如果函数抛出异常，C++会调用标准函数unexpected,此函数通常情况下会终止程序。而在Visual C++中，空异常说明和缺失异常类型列表具有相同的效果。**  

## 参考  

Introduction to Programming with C++, 3rd edition, Chapter 16  
