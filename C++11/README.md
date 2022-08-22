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

### 6.静态断言
在过往通常使用assert，在C++11引入了static_assert
``` c++
static_assert(常量表达式,"提示的字符串");
static_assert(sizeof(void*) == 4, "64位系统不支持");

```
### 7.nullptr
nullptr是为了解决C++中NULL的二义性问题，而引进的一种新类型。因为NULL实际上代表的是0。

测试的程序可以看`nullptr.cpp`。当重载的函数具有int和int*两种参数的时候。函数调用参数是NULL，那么可能调用的就是fun(int)这个函数。

### 8.强类型枚举
旧的枚举类型的缺陷：
``` c++
enum Status {OK, Error};
//enum Status2 {OK, Error};//重定义

//不能指定类型
Status e = OK;
cout << sizeof(e) << endl
```

``` c++
enum class Status {OK, Error};
enum struct Status2 {OK, Error};

Status flag = OK; //err，必须有枚举类型的作用域
Status flag = Status::OK; //

//可以指定类型
enum struct Status: char {OK, Error};

```

### 9.常量表达式
常量表达式主要是允许一些计算发生在编译时而不是运行时，这将是很大的优化。但也有一些限制：
- 函数只能有一个return语句（允许包含typedef、using、静态断言）；
- 函数必须有返回值；
- 在使用前必须已有定义；
- return返回语句表达式中不能使用非常亮表达式的函数、全局数据，必须是常量表达式
``` c++
const int GetNum(){
    return 3;
}

//常量表达式，发生在编译阶段
constexpr int GetNum(){
    return 3;
}
```

### 10.原生字符串字面值
所见即所得，`R"()"`括号之间的格式是怎样的，输出就是怎样。
```
cout << R"(hello,\n\n
world)" << endl;
```

### 11.委托构造
和己成构造函数类似，委托构造函数可以减少程序员书写构造函数的时间。允许一个构造函数的定义使用另一个构造函数，但必须通过初始化列表来操作。
``` c++
class Test{
public:
//委托构造，一定要通过初始化列表的方式
    Test():Test(1,'a'){}
    Test(int x):Test(x,'b'){}
    Test(char y):Test(11,y){}
    Test():a(x),b(y){}

    int a;
    char b;
}
```

### 12.final和override
final：阻止类的进一步派生和虚函数的进一步重写；
override：确保在派生类中声明的函数跟基类的虚函数有相同的签名；

### 13.类默认函数的控制：default和delete函数
1. `= default`让编译器提供一个默认的构造函数，效率比用户写高一些。
``` c++
class X{
public:
    X() = default;
    //只能修饰类中默认提供的：无参构造、拷贝构造、赋值运算符重载、析构函数等等。
};
```

2. 使用`=delete`之后，使函数被禁用。不仅仅用于特殊的成员函数，也可以作用于其他成员函数。

### 14.右尖括号的改进
``` c++
vector<vector<int>> arr;    //过去不允许，C++11后允许
```

### 15. 类型的别名
详情可看`alias.cpp`

### 16. 函数模板的默认模板参数
支持函数模板带默认的模板参数
``` c++
template<class T=int, class T2> void func2(T a, T2 b){}
```

### 17. 可变参数模板
``` c++
template<class ... T>   //T叫模板参数包
void func(T... args)    //args叫函数参数包
{
    cout << "num = " << sizeof(args) << endl;
}
```
递归方式展开函数参数包和非递归方式展开，详情请看`variable_args.cpp`


### 18. 左值引用和右值引用

#### 什么是左值和右值
可以取地址的、有名字的就是左值，反之，不能取地址的，没有名字的就是右值。那么这个加法赋值表达式中，&a是允许的操作，但&(b+c)这样的操作是不能通过编译的，因此a是一个左值，(b+c)是一个右值。
``` c++
int b = 1;
int a = 2;
int c = a + b;
```
相对于左值，右值表示字面常量、表达式、函数的非引用返回值等。

#### 什么是左值引用和右值引用

左值引用是对左值进行引用的类型，右值引用则是对一个右值进行引用的类型。
都属于引用类型，因此声明的时候都需要立即进行初始化。

### 19. 移动语义于移动构造函数
右值引用是用来支持转移语义的。转移语义可以将资源（堆，系统对象等）从一个对象转移到另一个对象，这样额能够减少不必要的临时对象的创建、拷贝以及销毁，能够大幅度提高C++应用程序的性能。
转移语义是和拷贝语义相对的，可以类比为文件的剪切与拷贝，当我们将文件从一个目录拷贝到另一个目录时，速度比剪切慢很多。
通过转移语义，临时对象中的资源能够转移到其他的对象里。

### 20. move
`std::move()`的作用就在于将一个左值转换为一个右值。

### 21. forward
`std::forward()`略

### 22. 闭包
指的是带上下文的函数，就是说有状态的函数。
函数是代码，状态是一组变量，将代码和一组变量捆绑(bind)，就形成了闭包。
必报的状态捆绑，必须发生在运行时。

闭包的实现：
1. 使用仿函数来实现,看`functor.cpp`
2. `std::bind` 绑定器,它可以预先把指定可调用实体的某些参数绑定到已有的变量，产生以恶搞新的可调用实体。
3. bind和function的结合使用

> std::function 是一个可调用对象包装器，是一个类模板，可以容纳除了类成员函数指针之外的所有可调用对象，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟它们的执行。
> - 定义格式：std::function<函数类型>。
> - std::function可以取代函数指针的作用，因为它可以延迟函数的执行，特别适合作为回调函数使用。它比普通函数指针更加的灵活和便利。

> 可将std::bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。std::bind将可调用对象与其参数一起进行绑定，绑定后的结果可以使用std::function保存。
> std::bind主要有以下两个作用：
> 1. 将可调用对象和其参数绑定成一个仿函数
> 2. 只绑定部分参数，减少可调用对象传入的参数

### 23. lambda表达式
lambda表达式由三部分组成，分别是捕获列表、参数、函数体。

捕获列表：
``` c++
auto f1 = [=](){}; //以值传递方式捕获外部变量
auto f2 = [&](){}; //以引用方式捕获外部变量
auto f3 = [&, a](){};
auto f4 = [=, &a](){};
auto f5 = [=]() mutable {
    a++;
    cout << tmp << endl;
}; //默认情况下，lambda函数，以const修饰函数体，值传递无法修改，向修改要加mutable
auto f6 = [this](){};//在类中使用，捕获所有类成员变量
```