#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "12345";
    cout << stol(str,0, 10) << endl;
}