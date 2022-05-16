# union and enum  

## union  

共用体能存储不同的数据类型，但只能同时存储其中的一种类型。共用体的用途之一是节省内存。  

```c++
union one4all {
    int int_val;
    long long ll_val;
    char char_val;
};

one4all oa;
cout << sizeof(oa) << endl; // union的长度为最大成员长度，output 8

oa.int_val = 6;
cout << oa.int_val << endl; // output 6

oa.ll_val = 5000;
cout << oa.ll_val << endl; // output 5000

cout << oa.int_val << endl; // 原来的int_val已经丢失，output 5000
```

## 参考  

C++ Primer Plus, Chapter 4  
