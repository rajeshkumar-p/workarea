/* Program to demonstrate bubble sort algorithm

Bubble sort/Sinking sort 
 * Sorting algorithm works by repeatedly stepping through the list to be sorted.
 * Comparing each pair of adjacent items and swapping them if they are in the 
   wrong order. 
 * Pass through the list is repeated until no swaps are needed, which indicates 
   that the list is sorted. 
 * Algorithm gets its name from the way smaller elements "bubble" to the top of 
   the list. 
 * Because it only uses comparisons to operate on elements, it is a comparison 
   sort. 

Algorithm details
 * It requires n-1 passes to sort an array.
 * In each pass every element a[i] is compared with a[i+1], for i=0 to (n-k-1), 
   where k is the pass number and if they are out of order i.e. if a[i]>a[i+1], 
   they are swapped.
 * This will cause the largest element to move up or bubble up.
 * Thus after the end of the first pass the largest element in the array will be 
   placed in the last or nth position and on the next pass, the next largest 
   element will be placed at position (n-1). 
 * This continues for each successive pass until the last or (n-1)th pass when 
   the second smallest element will be placed at the second position.

 We can optimize this by adding one more variable swapped to set true or false, 
 so that if there is no swap in the pass then the array is sorted
 */

#include <stdio.h>

void bubble_sort(int arr[], int n)
{
   int k; // pass n - 1
   int i; // iterator for each pass
   int temp;

   for(k=1; k<=n-1; k++)
   {
      for(i=0; i<n-k-1; i++)
      {
         if(arr[i] > arr[i+1])	
         {
            temp     = arr[i];
            arr[i]   = arr[i+1];
            arr[i+1] = temp; 		
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
