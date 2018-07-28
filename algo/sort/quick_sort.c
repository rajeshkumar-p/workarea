/*
 * C Program to Perform Quick Sort on a set of Entries from a File 
 * using Recursion
 */

#include <stdio.h>

void quicksort(int list[], int low, int high)
{
	int pivot, i, j, temp;

	if (low < high)
	{
		// choosing pivot element as first element
		pivot = low;
		i = low;
		j = high;

		while (i < j) 
		{
			// move towards right until the element in the 
			// list is larger than pivot element
			while (list[i] <= list[pivot] && i <= high) i++;

			// move towards left until the element in the 
			// list is lesser than pivot element
			while (list[j] > list[pivot] && j >= low) j--;

			// now swap those two elements pointed by
			// left and right pointer
			if (i < j)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}

		// now i and j crossed each other		
		// now swap the pivot element with
		// right pointer then partition complete
		temp = list[j];
		list[j] = list[pivot];
		list[pivot] = temp;

		quicksort(list, low, j - 1);
		quicksort(list, j + 1, high);
	}
}

int main()
{
	int list[50];
	int size, i;

	printf("Enter the number of elements: ");
	scanf("%d", &size); 
	printf("Enter the elements to be sorted:\n");
	for (i = 0; i < size; i++)
		scanf("%d", &list[i]);

	quicksort(list, 0, size - 1);

	printf("After applying quick sort\n");
	for (i = 0; i < size; i++)
		printf("%d ", list[i]);

	printf("\n");
	return 0;
}

