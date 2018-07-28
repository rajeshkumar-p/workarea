/*
Interesting Facts about the Local Class

1) A local class type name can only be used in the enclosing function. 
2) All the methods of Local classes must be defined inside the class only.
3) A Local class cannot contain static data members. It may contain 
   static functions though.
4) Member methods of local class can only access static and enum variables 
   of the enclosing function. Non-static variables (auto) of the enclosing 
   function are not accessible inside local classes. 
5) Local classes can access global types, variables and functions. Also, 
   local classes can access other local classes of same function.

*/

#include <iostream>
using namespace std;

void f();
int main()
{
	f();
	// myclass not known here
	return 0;
}

void f()
{
	class myclass {
		int i;
		//static int j; ERROR
		public:
		void put_i(int n) { i=n; }
		//void put_i(int n); ERROR
		int get_i() { return i; }
	} ob;

	//void myclass::put_i(int n) 	{ i = n; }; ERROR
	ob.put_i(10);
	cout << ob.get_i();
	cout << "\n";
}

