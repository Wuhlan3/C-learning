#include<iostream>
#include<functional>
using namespace std;
//1. 普通函数
void func()
{
    cout << __func__ << endl;
}
//2. 类中静态函数
class Test
{
public:
    static int test_func(int a)
    {
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

//3. 类中的仿函数
class MyFunctor{
public:
    //仿函数，重载operator()
    int operator()(int a){
        cout << __func__ << "(" << a << ") ->: ";
        return a;
    }
};

int main(){

    //1. 绑定普通函数
    function<void(void)> f1 = func;
    f1();   //等价于func()

    //2. 绑定类中的静态函数
    function<int(int)> f2 = Test::test_func;
    cout << f2(10) << endl;  //Test::test_func

    //3. 绑定类中的仿函数，绑定对象, 仿函数调用obj
    MyFunctor obj2;
    function<int(int)> f3 = obj2;
    cout << f3(1) << endl;
}