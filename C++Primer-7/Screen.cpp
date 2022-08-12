#include<iostream>
/* inline 和 重载 和 mutable
有可能会被inline的情况：
1.在函数定义的时候，加上inline关键字
2.函数较短，没有循环或递归，用-O2或-O3编译
3.类成员函数，在类定义的时候，直接写了函数体，而且函数体较短
*/
class Screen {
    public:
        //等价 typedef std::string::size_type pos;
        using pos = std::string::size_type;

        Screen() = default;
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
        char get() const { return contents[cursor]; }   //读取光标处的字符，隐式内联
        inline char get(pos ht, pos wd) const;          //参数不同，重载，显式内联
        Screen &move(pos r, pos c);                     //能在之后被设为内联

        void some_member() const;   //常函数，但是可以修改mutable

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;

        mutable size_t access_ctr;
};

// move 将光标移动到特定位置
inline Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

//get 获取光标处的字符 在类内部已经声明了inline
char Screen::get(pos r, pos c) const { 
    pos row = r * width;
    return contents[row + c];
}

// some_member 保存了一个计数值，用来记录该成员被调用的次数
void Screen::some_member() const {
    ++access_ctr;
    //该成员需要完成的其他工作
}