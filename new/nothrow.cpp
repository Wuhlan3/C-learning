#include <iostream>
#include <string>
using namespace std;

/*
void * operator new(std::size_t,const std::nothrow_t&) throw();
void operator delete(void*) throw();
*/

int main()
{
	char *p = new(nothrow) char[100000000000000000];
	if (p == NULL) 
	{
		cout << "alloc failed" << endl;
	}
	delete p;
	return 0;
}
//运行结果：alloc failed