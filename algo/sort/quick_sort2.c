# include <stdio.h>
# include <stdlib.h>

#define DEBUG 1

int partition(int *a, int low, int high)
{
   int pivot    = high;    // last element is pivot element 
   int temp;
  
   //while(low < high)
   while(1)
   {
#if DEBUG
      printf("\n low : %d high %d pivot :%d a[low] : %d a[high] : %d", low,
high, pivot, a[low], a[high]);
      sleep(1); 
#endif
      while(a[low] <= a[pivot])
           low++;
      while(a[high] > a[pivot])
           high--;
     
      // swap two non-confirming elements 
      if(low < high)
      {
         temp    = a[low];
         a[low]  = a[high];
         a[high] = temp;
      }
      else
      { 
         // place pivot element in correct place
         temp  = a[pivot];
         a[pivot] = a[high];
         a[high] = temp;
         break;
      }
   }
#if 0   
   // place pivot element in correct place
   temp  = a[pivot];
   a[pivot] = a[high];
   a[high] = temp;
#endif
 
   return high;
}

int quicksort(int *a,int low,int high)
{
   int pi;
   int i;

   if(low <= high)
   {

      pi = partition(a, low, high);
#if DEBUG 
      printf("\n pivot index is : %d", pi);
      printf("\n pivot element is : %d", a[pi]);
      printf("\n After Partition : \n"); 
      for(i = 0;i<=high;i++)
         printf("\t %d",a[i]);
#endif
      quicksort(a, low,  pi-1);
      quicksort(a, pi+1, high);
   }
}

void printArray(int *arr, int n)
{
  int i;
   for(i = 0;i<10;i++)
        printf("\t %d",arr[i]);
   printf("\n");
}

int main()
{
   int arr1[10] = {10,3,2,5,8,40,32,31,6,7};
   int arr2[10] = {10,31,22,50,8,7,6,5,4,3};
   int arr3[10] = {1,2,3,4,5,6,7,8,9,10};
   int arr4[10] = {10,9,8,7,6,5,4,3,2,1};
   int arr5[10] = {10,10,8,8,6,6,4,4,2,2};
   int i;  
 
   printf("\n Before Sort : \n");
   printArray(arr1,10); 
   printArray(arr2,10); 
   printArray(arr3,10); 
   printArray(arr4,10); 
   printArray(arr5,10); 
   //quicksort(arr1,0,9);
   //quicksort(arr2,0,9);
   //quicksort(arr3,0,9);
   //quicksort(arr4,0,9);
   quicksort(arr5,0,9);
   printf("\n After Sort : \n"); 
   printArray(arr1,10); 
   printArray(arr2,10); 
   printArray(arr3,10); 
   printArray(arr4,10); 
   printArray(arr5,10); 
}
