/**************************************************************************
Binary Search - Divide and Conquer Algorithm

**************************************************************************/
#include <stdio.h>

int binarysearch_iter(int a[],int n,int low,int high)
{ 
	int mid;
    mid = (low + high)/2;

	while((low <= high) && (a[mid] != n))
	{
		if(n < a[mid])
			high = mid - 1;
		else	
			low = mid + 1;

    	mid = (low + high)/2;
    }

	if (low > high) 
	{
		printf("\n Element not present in the List \n");	
		return -1;
	}
	else
	{		
		printf("\n Element %d is at position %d\n",a[mid], mid+1);
        return (mid+1);
    }
}

int binarysearch_recur(int a[],int no,int low,int high)
{ 
	int mid;

	if (low > high) 
	{
		printf("\n Element not present in the List \n");	
		return -1;
	}	

    mid = (low + high)/2;
    if(no == a[mid])
    { 
		printf("\n Element %d is at position %d \n", a[mid], mid+1);
        return 0;
    }

	if(no < a[mid])
	{ 
		high = mid - 1;
		binarysearch_recur(a,no,low,high);
	}

	if(no > a[mid])
	{ 
		low = mid + 1;
        binarysearch_recur(a,no,low,high);
    }
}

int main()
{

int a[6] = {10,20,30,40,50,60};
int i;

printf("\n");
for(i=0; i<6; i++)
 printf("\t %d", a[i]);
printf("\n");
binarysearch_iter(a,30,0,5);
binarysearch_recur(a,30,0,5);
binarysearch_iter(a,10,0,5);
binarysearch_recur(a,10,0,5);
binarysearch_iter(a,60,0,5);
binarysearch_recur(a,60,0,5);
binarysearch_iter(a,55,0,5);
binarysearch_recur(a,55,0,5);
binarysearch_iter(a,100,0,5);
binarysearch_recur(a,100,0,5);

printf("\n\n Good Bye \n\n");
return 0;
}	

