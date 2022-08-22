#include<iostream>
using namespace std;

//递归终止函数
template<class T>
void debug(T t){
    cout << t << endl;
}

//可变参数的模板函数
//参数包展开函数
template<class T1, class ... T2>
void debug(T1 first, T2 ... last){
    cout << first << endl;
    debug(last...);
}

//非递归方式展开
//...............................................................
template <class T>
void print(T arg){
    cout << arg << endl;
}

template <class ... Args>
void expand(Args ... args){
    int a[] = {(print(args), 0)...};    //通过初始化列表可以展开Args
}

int main(){
    debug(1,"hello,world",3,4.4444);
    expand(1,"hello,world",3,4.4444);
    return 0;
}

