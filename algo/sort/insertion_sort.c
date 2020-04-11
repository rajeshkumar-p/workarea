/* 
Insertion Sort

* Insertion sort is a simple sorting algorithm that works the way we sort playing
  cards in our hands.
* It is a comparison sort in which the sorted array (or list) is built one entry 
  at a time
* It is much less efficient on large lists than more advanced algorithms such as 
  quicksort, heapsort, or merge sort

* In insertion sort, we pick up a particular value and then insert it at the 
  appropriate place in the sorted sub list.

Insertion sort algorithm requires n-1 passes, 

Pass 1: a[1] is inserted either before or after a[0] so that a[0] and a[1] are
        sorted.
Pass 2: a[2] is inserted either before a[0] or between a[0] and a[1] or after
        a[1] so that the elements a[0], a[1], a[2] are sorted.                           
Pass 3: a[3] is inserted either before a[0] or between a[0] and a[1] or between
        a[1] and a[2] or after a[2] so that the elements a[0], a[1], a[2], a[3] 
        are sorted. 
   
Pass k: a[k] is inserted in its proper place in the sorted sub array a[0], a[1],
        a[2],…a[k-1] so that the elements a[0], a[1], a[2],…a[k-1],a[k] are sorted.           
                                                                                
Pass n-1: a[n-1] is inserted in its proper place in the sorted sub array a[0],
          a[1], a[2],…a[n-2] so that the elements a[0], a[1], a[2],…a[n-1] are 
          sorted.          

*/ 

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

   printf("\n Array Before Sort \n");
   print_arr(a,5);

   insertion_sort(a,5);

   printf("\n Array After Sort \n");
   print_arr(a,5);

   return 0;
}
