#include<iostream>
using namespace std;
void fun(int a) { std::cout << "int"; }
void fun(void* ptv) { std::cout << "void*"; }
 
 
int main()
{
	fun(0);
	fun(NULL);
	fun(nullptr);
}