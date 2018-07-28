#include <stdio.h>


int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int div(int a, int b) { return a/b; }

// func pointer  
typedef int (*arith_func)(int a, int b);
arith_func arr_arith_func[] = {add,sub,mul,div};

int oper(int (*ptr_func)(int , int ),int a, int b)
{
  printf("\n Result is : %d", ptr_func(a,b));
}

int main()
{
   int a=20, b=10;
   int c=30, d=10;  
   int i; 

   oper(add,a,b); // oper(&add,a,b) is also correct
   oper(sub,a,b);
   oper(mul,a,b);
   oper(div,a,b);

   printf("\n");
   for(i=0; i<4; i++)
      printf("\n Result is : %d", arr_arith_func[i](c,d)); 

   return 0;
}
