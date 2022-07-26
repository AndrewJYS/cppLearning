# 模板

## 模板类  

**注意：**  
**对于模板类，定义和实现放在一起更安全，某些编译器不支持将他们分开**  

下面是用法举例：  

```c++
template<typename T> //应在类声明前加上模板前缀
class Stack
{
public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    bool isEmpty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;

private:
    T* elements;
    int size;
    int capacity;
    void ensureCapacity();
};

template<typename T>
Stack<T>::Stack(): size(0), capacity(16) //注意作用域解析符前的类名是Stack<T>
{
    elements = new T[capacity];
}

//其余代码见introduction-to-programming-with-cpp/improvedStack文件夹
```

C++允许为模板类中的类型参数指定一个默认类型，例如  

```c++
template<typename T = int>
class Stack {...};
```

这样就可以使用下述代码声明模板类对象  

```c++
Stack<> stack;
```

在模板前缀中，还可以使用非类型参数，例如在Stack类中，可以将数组容量声明为一个参数  

```c++
template<typename T, int capacity> 
class Stack {
    ...
private:
    T elements[capacity];
    int size;
};
```

用法如下：

```c++
Stack<string, 500> stack;
```

## 参考  

Introduction to Programming with C++, 3rd edition, Chapter 12  
