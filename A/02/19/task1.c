#include <stdio.h>

void minmax(int *, int, int *, int *);

int main() {

	int size;
	int arr[500];
	int *min = 0, *max = 0;

	scanf("%d", &size);

	for(int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	min = &arr[0];
	max = &arr[0];

	minmax(arr, size, min, max);

	return 0;
}

void minmax(int *arr, int size, int *min, int *max) {

	for(int i = 0; i < size; i++) {
		if(*min > arr[i]){
			min = &arr[i];
		}
		
		if(*max < arr[i]){
			max = &arr[i];
		}
	}

	printf("%d", *max + *min);
}
