/*
cc -g welcome_thread.c -lpthread
*/

#include <stdio.h>
#include <pthread.h>

void* welcome_func(void *arg)
{
  printf("\n Welcome to CSC ");
  return NULL; 
} 

int main()
{
   pthread_t thread_id;

   printf("\n Before Thread \n");
   pthread_create(&thread_id, NULL, welcome_func, NULL);
   pthread_join(thread_id, NULL);
 
   printf("\n After Thread \n"); 
   return 0;
}
 
