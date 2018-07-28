#include <stdio.h>

// func pointer  
int (*ptr_func)(int a, int b);

int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int div(int a, int b) { return a/b; }

int oper(int (*ptr_func)(int , int ),int a, int b)
{
  printf("\n Result is : %d", ptr_func(a,b));
}


int main()
{
   int a=20, b=10;
   oper(add,a,b); // oper(&add,a,b) is also correct
   oper(sub,a,b);
   oper(mul,a,b);
   oper(div,a,b);

   return 0;
}
