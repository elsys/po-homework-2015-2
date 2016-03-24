#include <stdio.h>

void is_min(int *max, int *min) {
	if(*max < *min)
		*min = *max;
}

void is_max(int *max, int *min) {
	if(*max > *min)
		*min = *max;
}

void minmax(int *arr, int size, int *min, int *max) {
	int i = 0;
	*min = 0, *max = 0;
	for(; i < size; i++) {
		is_max(&arr[i], max);
		is_min(&arr[i], min);
	}
}

int main() {

	int n, i = 0;
	scanf("%d", &n);
	int arr[n];
	for(; i < n; i++)
		scanf("%d", &arr[i]);
	int min, max;
	minmax(arr, n, &min, &max);
	printf("%d", max + min);
	return 0;
}