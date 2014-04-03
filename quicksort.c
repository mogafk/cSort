#include <stdio.h>
#include <math.h>

#define swap(A, B) int t = B; B = A; A = t;

int partition(int *arr, int l, int r){
	int x = arr[r];
	int i = l-1, j = l;
	for(; j<r-1; j++){
		if(arr[j] <= x){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
};
void quickSort(int *arr, int l, int r){
	if(l<r){
		int q = partition(arr, l, r);
		quickSort(arr, l, q-1);
		quickSort(arr, q+1, r);
	}
};

int main(){
	int arr[10] = {5,124,52,314,52,24,2356,241,4151,5};

	quickSort(arr, 0, 10);

	int i;
	for (i = 0; i < 10; ++i){
		printf("%4d\n", arr[i]);
	}

}