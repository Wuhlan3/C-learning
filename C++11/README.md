## C++11新特性
### 1.auto关键字
auto修饰局部变量，作用是自动推导类型。
易错点：
1. 定义变量时一定要初始化
2. vs不支持函数形参是auto变量，但是QT可以
3. auto不能作为自定义类型的成员变量
4. auto不能作为数组类型。
5. 模板实例化的时候，类型不能是auto

### 2.decltype
有点像auto的反函数，auto可以让你定义一个变量，decltype则是让你获取变量的类型。需要使用头文件`#include<typeinfo>`

具体应用看`decltype.cpp`

### 3.追踪返回类型
追踪返回类型配合auto与decltype会真正释放C++11中泛型编程的能力；简化函数的定义，提高代码的可读性。

而auto占位符和->return_type也就是构成追踪返回类型函数的两个基本元素。
``` c++
int func(int, int);
auto func2(int, int)->int;

auto func3(int a, double b)->decltype(a+b){
    return a+b;
}

template<class T1, class T2>
auto mul(const T1 &t1, const T2 &t2)->decltype(t1*t2){
    return t1*t2;
}
```

### 4.列表初始化
``` c++
struct Test temp = {1,2,"mike"};

int a = 1;
int b = {1};
int c{2};

int arr[] = {1,2,3};
int arr[]{1,2,3};
```

列表初始化可以防止类型收窄：
``` c++
int a = 1024;   //数据丢失
char b = a; //此时
char b = {a};   //编译error/warning，从int抓换到char需要收缩转换
```

### 5.基于范围的for循环
通常用法：
``` c++
for(int &temp : arr){
    //...
}
```
但是需要注意，形参中的数组不是数组，是指针变量，无法确定元素个数
``` c++
void func(int a[]){
    //范围无法确定
    for(auto &temp : a){
        //...
    }
}
```