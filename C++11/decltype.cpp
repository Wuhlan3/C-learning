#include<typeinfo>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int i;
    decltype(i) j = 0;
    cout << typeid(j).name() << endl;

    float a;
    double b;
    decltype(a + b) c;
    cout << typeid(c).name() << endl;

    vector<int> arr;
    decltype(arr.begin()) k;
    for (k = arr.begin(); k != arr.end(); ++k){

    }

    enum
    {
        OK,
        Error
    } flag; //匿名类型的枚举变量
    decltype(flag) flag2 = OK;   //使用decltype之后可以再次声明这样的枚举变量

    cout << flag2 << endl;
}