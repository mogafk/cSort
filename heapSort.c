#include <stdlib.h>
#include <stdio.h>


#define ARR_SIZE 10
#define HEAP_HIGH 11

#define PARENT(A, N) A[N/2]
#define LEFT(A, N) A[N*2]
#define RIGHT(A, N) A[N*2+1]
#define swap(A, B) int t = B; B = A; A = t;

int arrLen = 10;

void heapifyMax(int arr[], int n){
	int indexOfMax = n;
	printf("%d <", arr[n]);
	if(n*2 < arrLen && arr[n] < LEFT(arr, n))
		indexOfMax = n*2;
	if(n*2+1 < arrLen && arr[indexOfMax] < RIGHT(arr, n))
		indexOfMax = n*2+1;
	if(indexOfMax != n){
		printf("%d\n", arr[indexOfMax]);
		swap(arr[n], arr[indexOfMax]);
		heapifyMax(arr, indexOfMax);
	}else
		printf("none\n");
}

void heapBuild(int arr[]){
	int i;
	for(i = ARR_SIZE/2; i >= 1 ; i--)
		heapifyMax(arr, i);
}

void heapSort(int arr[]){
	heapBuild(arr);
	int i;
	for(i = 10; i > 1; i-- ){
		swap(arr[1], arr[i]);
		arrLen--;
		heapifyMax(arr, 1);
	}
}

int main()
{
	int arr[100] = {0,2,4,1,3,5,1,24,8,1,9};
	// heapBuild(arr);

	// test = 200;
	// printf("%d\n", test);

	heapSort(arr);
	// printf("%d\n\n", RIGHT(arr, 5));

	int i;
	for (i = 0; i < HEAP_HIGH; ++i)
	{
		printf("%3d\n", arr[i]);
	}

}