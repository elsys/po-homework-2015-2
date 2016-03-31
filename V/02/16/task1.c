#include <stdio.h>
#include <string.h>

void minmax(int *arr, int size, int *min, int *max);

int main() {
	int n, min, max;
	int arr[500];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	minmax(arr, n, &min, &max);
	int sum = min + max;
	printf("%d", sum);	

	return 0;
}


void minmax(int *arr, int size, int *min, int *max) {

	*min = arr[0];
	*max = arr[0];
	for (int i = 0; i < size; i++) {
		if (*min > arr[i]) {
			*min = arr[i];
		}
		if (*max < arr[i]) {
			*max = arr[i];
		}
	}
}

