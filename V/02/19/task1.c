#include <stdio.h>

void minmax(int*, int, int*, int*);

int main() {
	int arr[200], n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int max, min;
	minmax(arr, n, &min, &max);
	printf("%d\n", max + min);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max) {
	int i; 
	for(i = 0 ; i < size; i++) {
		if(arr[i] > *max) {
			*max = arr[i];
		}
		else if(arr[i] < *min) {
			*min = arr[i];
		}
	}
	
}