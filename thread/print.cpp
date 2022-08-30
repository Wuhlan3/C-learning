#include<iostream>
#include<thread>
using namespace std;



int main(){
    thread t1([]()
              { for (int i = 0; i < 10;  i ++)cout << "hello" << endl; });
    thread t2([]()
              { for (int i = 0; i < 10;  i ++)cout << "world" << endl; });
    t1.detach();
    t2.detach();
    return 0;
}