#include<iostream>

/*  封装与友元
封装的两个重要优点：
1. 确保用户代码不会无意间破坏封装对象的状态；
2. 被封装的类的具体实现细节可以随时改变，而无须调整用户级别的代码
*/

class Sales_data{
    // 为Sales_data的非成员函数所做的友元声明
    // 这样子，类可以允许其他类或者函数访问它的非公有成员函数。
    // 友元声明只能够在类内部，但它仅指明了权限。如果你希望用户能够调用某个友元函数，必须在友元声明之外再专门对函数进行一次声明。
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){}
    Sales_data(const std::string &s) : bookNo(s){}
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//比较特殊的构造函数，使用read函数来对成员进行赋值。
Sales_data::Sales_data(std::istream &is){
    read(is, *this);
}