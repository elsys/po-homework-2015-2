#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max) {
	int count, minmax;

	for (count = 0; count < size; count++) {
		scanf("%d", &arr[count]);
		*max = arr[count];
		*min = arr[count];
	}
	for (count = 0; count < size; count++) {
		if (*max < arr[count])
			*max = arr[count];
		if (*min > arr[count])
			*min = arr[count];

	}
	minmax = *min + *max;
	printf("%d", minmax);

}

int main() {
	int size, arr[500], min = 0, max = 0;
	scanf("%d", &size);
	minmax(&arr, size, &min, &max);

}
