/* 
Selection Sort :

* Selection sort algorithm sorts an array by repeatedly finding the minimum
element (considering ascending order) from unsorted part and putting it at the
beginning. 
* Algorithm maintains two subarrays in a given array.
  1) The subarray which is already sorted.
  2) Remaining subarray which is unsorted.

* In every iteration of selection sort, the minimum element (considering ascending
order) from the unsorted subarray is picked and moved to the sorted subarray. 

*/

/* Program for implementation for Selection Sort */

#include <stdio.h> 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx;
    int temp; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the minimum element with the first element 
        temp         = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i]       = temp;
    } 
}

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Array: \n"); 
    printArray(arr, n); 
    
    selectionSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
}  
