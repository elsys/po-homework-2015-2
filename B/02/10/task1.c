#include <stdio.h>
#include <string.h>
#define ARRSIZE 500

void minmax(int *, int, int *, int *);

int main () {

	int numbers[ARRSIZE];
	int counter = 0;
	int length;

	scanf("%d",&length);

	for (counter = 0; counter < length; ++counter)
	{
		scanf("%d",&numbers[counter]);
	}
	int min = 0, max = 0;
	
	minmax(numbers,length, &min, &max);

	return 0;
}

void minmax (int *arr, int size, int *min , int *max) {

	int index = 0;
	
	*min = arr[0];
	*max = arr[0];

	for (index = 1; index < size; ++index)
	{
		if (arr[index] > *max) *max = arr[index];
		if (arr[index] < *min) *min = arr[index];
	}

	int sum = 0;

	sum = *max + *min;

	printf("%d", sum);

}

