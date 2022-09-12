#include <iostream>
#include <string>
using namespace std;

/*
void* operator new(std::size_t) throw(std::bad_alloc);
void operator delete(void *) throw();
*/

int main()
{
	try
	{
		char *p = new char[100000000000000000];
		delete p;
	}
	catch (const std::bad_alloc &ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
//执行结果：bad allocation
 