# const与指针

## 保护数组  

为了防止函数无意中修改数组的内容，可在声明形参时使用关键字const  

```c++
void printArray(const int* a, int n) {
    a[0] = 5; //报错，因为const限定符
}

int main() {
    int a[5] = {1,2,3,4,5};
    printArray(a, 5);

    return 0;
}
```

## 常量指针  

常量指针指向一个不变的内存位置，但该内存位置的实际值时可以改变的。下述语句中第一个const表示常量数据，第二个const表示常量指针。  

```c++
const int* const a = new int(3);  
```

示例如下：  

```c++
int test = 2;
const int* b = new int(1);
//*b = 2;  // b是常量数据因此会报错
b = &test;
cout << *b << endl; // output 2

int* const c = new int(2);
*c = 6; // c是常量指针
c = &test; // 报错
```

**注意：**  
**不能把const指针赋值给非const指针**  

```c++
int* const d = new int(4);
int* e = &d; //报错，不能把const指针赋值给非const指针
```

## 参考  

C++ Primer Plus, Chapter 7.3  
Introduction to Programming with C++, 3rd edition, Chapter 11  
