#include<iostream>
using namespace std;

class X{
public:
    int i;
    int j;
public:
    X(int val) : j(val), i(j){} //这里i，会先被初始化
};

int main(){
    X *x = new X(10);
    cout << x->i << " " << x->j << " " << endl;
}