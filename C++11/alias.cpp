#include<iostream>
using namespace std;
#include<type_traits>


typedef int int32; //使用typedef给一个类型起别名
using my_int = int; //C++11的方式

int main(){
    //判断两个类型是否一致，如果是返回真，否则返回假
    cout << is_same<int32, my_int>::value << endl;
    return 0;
}