#include<stdio.h>

void minmax(int *arr, int *size, int *min, int *max);

int main()
{
	int arr[500];
	int size, num=1, i, min, max;
	scanf("%d", &size);
	scanf("%d", &arr[0]);
	min = arr[0];
	max = arr[0];
	while(num < size)
	{
		scanf("%d", &arr[num]);
        minmax(&arr[num], &size, &min, &max);
		num++;
	}
    printf("%d", min+max);
	return 0;
}

void minmax(int *arr, int *size, int *min, int *max)
{
    if (*min > *arr) *min = *arr;
    if (*max < *arr) *max = *arr;
}