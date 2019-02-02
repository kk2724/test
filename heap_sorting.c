#include <stdio.h>

void max_heaplify(int *A, int i, int heap_size)
{
	int l = (i << 1) + 1;
	int r = l + 1;
	int large = i;
	if(l < heap_size && A[l] > A[i])
	{
		large = l;
	}
	if(r < heap_size && A[r] > A[large])
	{
		large = r;
	}
	if(large != i)
	{
		int tmp = A[i];
		A[i] = A[large];
		A[large] = tmp;
		max_heaplify(A, large, heap_size);
	}
}

void build_heap(int *A, int heap_size)
{
	int i = heap_size / 2 -1;
	for(i=i;i>=0;i--)
	{
		max_heaplify(A, i, heap_size);
	}
}

void heap_sort(int *A, int heap_size)
{
	build_heap(A, heap_size);
	int i = 0;
	int m = heap_size;
	int tmp;
	for(i = 0;i < heap_size;i++)
	{
		tmp = A[0];
		A[0] = A[m-1];
		A[m-1] = tmp;
		m--;
		max_heaplify(A, 0, m);
	}
}



int main()
{
	//int A[] = {2, 8, 1, 7, 3, 5, 6, 4};
	int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	//int A[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
        int i = 0;

        //srand((unsigned int) time(NULL));
        for(i=0;i<10;i++)
                printf("%d  ",A[i]);
        printf("\n");

      	 heap_sort(A, 10);
	
	//build_heap(A, 10);
	
	//max_heaplify(A, 1, 10);

        for(i=0;i<10;i++)
                printf("%d  ",A[i]);
        printf("\n");
	
	return 0;
}
