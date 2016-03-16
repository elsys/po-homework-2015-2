#include <stdio.h>

void minmax(int *, int, int *, int *);

int main() {


	int numbers[500];
	int *min;
	int *max;
	int i, length;

	min = &numbers[0];
	max = &numbers[0];

	scanf("%d", &length);

	for(i = 0; i < length; i++) {
		scanf("%d", &numbers[i]);
	}

	minmax(numbers, length, min, max);

	return 0;
}

void minmax(int *arr, int size, int *min, int *max) {

	int i;

	for(i = 0; i < size; i++) {
		
		if(*min > arr[i])
		{
			min = &arr[i];
		}
		
		if(*max < arr[i])
		{
			max = &arr[i];
		
		}
	}

	printf("%d", *max + *min);
}