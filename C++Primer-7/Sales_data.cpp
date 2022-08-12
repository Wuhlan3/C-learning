#include<iostream>
struct Sales_data{
public:
    //成员函数
    std::string isbn() const { return bookNo; } //知识点一：isbn使用bookNo的时候，隐式调用了this->bookNo， this的目的总是指向这个对象。
                                                //可以看到this的定义，const Sales_data *this， 是一个指针常量，不可以改变它的指向。
                                                //知识点二：这里的const，是修改隐式指针this的类型。表示this是一个指向常量的指针，不可以修改所指向的内容。这样的函数称为常函数
                                                //这种写法可以提高函数的灵活性。可以把函数想象成 std::string isbn(const Sales_data * const this) { return this->bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const; 

public:
    //数据成员
    std::string bookNo; //因为编译器会先编译成员的声明，所以成员和函数体的次序没有关系。
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//外部定义成员函数
double Sales_data::avg_price() const {  //编译其看到这个函数名，能够理解剩余代码是在类的作用域内。
    if (units_sold){
        return revenue / units_sold;
    } else {
        return 0;
    }
}
Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;   //返回调用该函数的对象
}


// Sales_data的非成员接口函数
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

