#include<iostream>
/*委托构造函数*/
class Sales_data{
    friend std::istream &read(std::istream &, Sales_data &);
public:
//非委托构造函数使用对应的实参初始化成员
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){}
//其余构造函数全都委托到另一个构造函数
    Sales_data():Sales_data("", 0, 0){}
    Sales_data(const std::string &s):Sales_data(s, 0, 0){}
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); };

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};