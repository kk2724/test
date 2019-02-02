#include <stdio.h>

void merge_sort(int *A, int low, int high);
void merge(int *A, int low, int mid, int high);


void merge_sort(int *A, int low, int high)
{
	if(high-low > 0)
	{
		int mid = (low + high) / 2;
		merge_sort(A, low, mid);
		merge_sort(A, mid+1, high);
		merge(A, low, mid, high);
	}
}

void merge(int *A, int low, int mid, int high)
{
	int left[mid- low + 1];
	//int right[high - mid];
	int i=0, j=0, k=0;

	//copy A to the lef and right array 
	for(i=0;i < mid-low+1;i++)
	{
		left[i] = A[low + i];
	}

	/*
	for(i=0;i < high - mid;i++)
	{
		right[i] = A[mid + i + 1];
	}
	*/

	int *right = &A[mid+1];
	//uesed 3 loop to merge the data
	i = 0; j = 0; k = low;
	while (i < mid-low+1 && j < high-mid)
	{
		if(left[i] < right[j])
			A[k++] = left[i++];
		else
			A[k++] = right[j++];
	}
	while(i < mid-low+1)
	{
		A[k++] = left[i++];
	}
	while (j < high-mid)
	{
		A[k++] = right[j++];
	}

}


int main()
{
	int A[] = {5, 2, 4, 7, 1, 3, 8, 6, 9, 10, 12, 13, 17, 14, 23, 22};
	merge_sort(A, 0, 15);
	int i = 0;
	for(i=0;i<15;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}
