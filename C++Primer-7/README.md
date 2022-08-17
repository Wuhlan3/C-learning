## C++ Primer 第七章

### 一、构造函数的初始值有时候必不可少
如果成员是const，引用，或者属于某种未提供默认构造函数的类类型，我们必须使用初始值列表为这些成员提供初值。比如：

```
class ConstRef{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};


ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i){} 
```
### 二、成员初始化的顺序
成员初始化顺序与成员在类定义中的顺序一致。比如：
```
class X{
    int i;
    int j;
public:
    X(int val) : j(val), i(j){} //这里i，会先被初始化
    //有些编译其会warning，指出i和j的初始化顺序与定义不一样
};
```

### 三、抑制构造函数定义的隐式类型转换
使用explicit即可。详情可看`explicit.cpp`文件

### 四、聚合类
**聚合类**使得用户可以直接访问其成员，并且具有特殊的初始化语法形式。当一个类满足如下条件时，我们说它是聚合的：
- 所有成员都是public的；
- 没有定义任何构造函数；
- 没有类内初始值；
- 没有基类，也没有virtual函数。

比如：
```
struct Data{
    int ival;
    stirng s;
};

Data val1 = {0, "Anna"};    //可以这样子来初始化
```

### 五、小结
类是C++语言中最基本的特性。类允许我们为自己的应用定义新类型，从而使得程序更加简洁且易于修改。
类有两项基本能力：

一、数据抽象。即定义数据成员和函数成员的能力；二是封装，即保护类的成员不被随意访问的能力。通过将类的实现细节设为private，我们就能完成类的封装。类可以将其他类或函数设为友元，这样它们就能够访问类的非公有成员。

类可以定义一种特殊的成员函数：构造函数，其作用是控制初始化对象的方式。构造函数可以重载，构造函数应该使用构造函数初始值列表来初始化数据成员。
类还能定义可变或者静态成员。一个可变成员永远都不会是const，即使在const成员函数内也能修改它的值；一个静态成员可以是函数也可以是数据，静态成员存在于所有对象之外。