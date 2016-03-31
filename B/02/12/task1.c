#include <stdio.h>

void minmax (int *arr, int size, int *min, int *max);

int main () {
	int arr[500];
	int number_of_elem, count, min = 0, max = 0;

	do {
	scanf ("%d", &number_of_elem);
	} while (number_of_elem < 1 && number_of_elem > 500);

	for (count = 0; count < number_of_elem; count++) scanf ("%d", &arr[count]);

	minmax (arr, number_of_elem, &min, &max);

	return 0;
}

void minmax (int *arr, int size, int *min, int *max) {
	int count;

	*min = arr[0];
	*max = arr[0];

	for (count = 0; count < size; count++) {
	if (arr[count] < *min) *min = arr[count];
	if (arr[count] > *max) *max = arr[count];
	}

	printf ("%d", *max + *min);
}
