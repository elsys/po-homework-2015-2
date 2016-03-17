#include <stdio.h>

void minmax(int*, int, int*, int*);

int main() {
	unsigned short n;
	do
		scanf("%hu", &n);
	while(n <= 0 && n >= 500);
	int arr[n], min, max;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	minmax(arr, (int)n, &min, &max);
	printf("%d", max+min);

	return 0;
}


void minmax(int *arr, int size, int *min, int *max) {
	for(int i = 0; i < size; i++) {
		if(*min < *(arr+i))
			*min = arr[i];
		if(*max > arr[i])
			*max = arr[i];
	}
}