/*
Function overloading

* Function overloading is a feature in C++ where two or more functions can have 
  the same name but different parameters.
* Function overloading can be considered as an example of polymorphism feature 
  in C++.
* In C++ and Java, functions can not be overloaded if they differ only in the
  return type. 
*/

#include <iostream>

using namespace std;

/* function to compute area of a square */
int area(int side)
{
  return side * side;
}

/* function to compute area of a rectangle */
int area(int length, int breadth)
{
  return length * breadth;
}

int main()
{
  int side = 20;
  int length = 10, breadth = 20;
 
  cout<<"\n area of a square    : " << area(side);
  cout<<"\n area of a rectangle : " << area(length, breadth);
  cout<<"\n";
  
  return 0;
}
