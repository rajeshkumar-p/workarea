#include "apue.h"
#include "myprint.h"

// api to print array
void print_arr(int arr[], int n)
{
	int iter;
	printf("\n");
	for(iter = 0; iter < n; iter++)
		printf("\t %d", arr[iter]);	
	printf("\n");	
}	

// api to print list
void print_list(mynode1 *head)
{
	mynode1 *iter;

	if(head == NULL)
	{
		printf("\n List is Empty \n");
		return;	
	}	
	
	iter = head;	

	// iterate over the list upto the end
	printf("\n");	
	while(iter->next != NULL)
	{
		printf("%d\t", iter->value);
		iter = iter->next;	
	}		
	printf("%d\t\n", iter->value);
}	
