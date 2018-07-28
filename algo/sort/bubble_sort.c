/* Program to demonstrate bubble sort algorithm */

#include <stdio.h>

void bubble_sort(int arr[], int n)
{
   int k; // pass n - 1
   int j; // iterator for each pass

   int temp;

   for(k=1; k <= n-1; k++)
   {
      for(j=0; j < n-k-1; j++)
      {
         if(arr[j] > arr[j+1])	
         {
            temp   = arr[j];
            arr[j]   = arr[j+1];
            arr[j+1] = temp; 		
         }		
      }			
   }
}

int print_arr(int a[], int n)
{
   int i=0;
   printf("\n Array Elements : "); 
   for(i=0; i<n; i++)
      printf("\t %d", a[i]);
   printf("\n");
}

int main()
{
   int a[10] = {12,10,13,45,11,32,14,18,18,20};

   printf("\n Before Sort ");
   print_arr(a,10);
   printf("\n After Sort ");
   bubble_sort(a,10);
   print_arr(a,10);

   return 0;
}	
