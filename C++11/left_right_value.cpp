#include<iostream>
using namespace std;

int & func(){
    static int tmp;
    return tmp;
}

int func01(){
    return 10;
}

int miain(){
    int a;
    int &b = a; //ok
    // int &c = 1;//err
    const int &d = a;   //ok
    const int &e = 1;   //ok
    const int &f = func();    //ok

    //const int & 是一个万能引用

    //右值引用
    int &&g = 10;
    int &&h = func01();

    int i = 10;
    int j = 20;
    int &&k = i + j;

    int l = 10;
    //int &&m = l;    //err,不能将一个左值赋给右值引用

    return 0;
}