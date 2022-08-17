#include<iostream>

/*  抑制构造函数定义的隐式类型转换
*/

class Sales_data{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){}

    //阻止这两个进行隐式转换
    explicit Sales_data(const std::string &s) : bookNo(s){}
    explicit Sales_data(std::istream &);
    
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//任何构造函数都不能用于隐式地构造Sales_data对象，之前的两种用法无法通过编译
int main(){
    Sales_data *item = new Sales_data();
    std::string null_book = "9-999-99999-9";
    // 之前的两种用法无法通过编译
    // item->combine(null_book);
    // item->combine(std::cin);
}