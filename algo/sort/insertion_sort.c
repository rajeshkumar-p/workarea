/* Program to demonstrate Insertion Sort Algorithm */

#include <stdio.h>

void insertion_sort(int a[], int n)
{

   int k; // no of pass
   int j; // iterator
   int temp;

   for (k=1; k <= (n-1);  k++)
   {	
      temp = a[k];	// new element to be sorted
      j = k-1;      // element upto which already sorted

      // new element is compared with sorted list last element
      // if the new element is less than sorted element then
      // it need to be placed somewhere before, so please shift
      // the element by one position to make space for insertion
      // repeat this procedure until selected element is greater
      // than the sorted element or we reach start

      while((temp < a[j]) && j>=0)
      {	 
         a[j+1]=a[j];
         j=j-1;
      }		
      a[j+1]=temp;
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
   int a[5] = {2,33,10,15,16};

   printf("\n List Before Sort \n");
   print_arr(a,5);

   insertion_sort(a,5);

   printf("\n List After Sort \n");
   print_arr(a,5);

   return 0;
}
