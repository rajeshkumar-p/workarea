#include <stdio.h>
#include <pthread.h>

void* welcome_func(void *arg)
{
  //int *val = (int *) arg;
  
  int *val;
  val = (int *) arg;

  printf("\n Welcome to CSC : %d", *val);
  *val = *val + 1;
  return NULL; 
} 

int main()
{
   pthread_t thread_id;
   int i;

   printf("\n Before Thread \n");
   for(i=0;i<50;i++)
   {
     pthread_create(&thread_id, NULL, welcome_func, (void *)&i);
     pthread_join(thread_id, NULL);
   }
 
   printf("\n After Thread \n"); 
   return 0;
}
 
