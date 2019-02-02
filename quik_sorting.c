#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int lo, int hi)
{
	int i = lo - 1;
	int j = lo;
	int tmp = 0;

	//srand((unsigned int) time(NULL));
	
	int k = lo + rand() % (hi-lo+1);
	tmp = A[k];
	A [k] = A[hi];
	A[hi] = tmp;
	
	int key = A[hi];
	for(j = lo;j < hi;j++)
	{
		if(A[j] <= key)
		{
			i = i+1;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i+1];
	A[i+1] = A[hi];
	A[hi] = tmp;

	return i + 1;

}

void quik_sort(int *A, int lo, int hi)
{
	if(hi<=lo)
		return;

	int mi = partition(A, lo, hi);
	quik_sort(A, lo, mi-1);
	quik_sort(A, mi+1, hi);
}


int main()
{
	int A[] = {2, 8, 1, 7, 3, 5, 6, 4};
	int i = 0;

	srand((unsigned int) time(NULL));
	for(i=0;i<8;i++)
		printf("%d  ",A[i]);
	printf("\n");

	quik_sort(A, 0, 7);

	for(i=0;i<8;i++)
                printf("%d  ",A[i]);
        printf("\n");

	
	return 0;

}
