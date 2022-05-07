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

const int* const a = new int(3);  
第一个const表明常量数据，第二个const表明常量指针  

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

```c++
int* const d = new int(4);
int* e = &d; //报错，不能把const指针赋值给非const指针
```

## 