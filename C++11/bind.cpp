#include<iostream>
#include<functional>
using namespace std;

void func(int x, int y){
    cout << x << " " << y << endl;
}

int main(){
    std::bind(func, 11, 22)(); //输出11 12

    //std::placeholders::_1 占位符函数调用时，被第一个参数替换
    std::bind(func, std::placeholders::_1, std::placeholders::_2)(11, 22);

    using namespace std::placeholders;
    bind(func, 11, _1)(22, 33, 44);
}