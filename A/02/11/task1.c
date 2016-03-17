#include <stdio.h>
#include <string.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int i = 0, n, arr[500];
	int minimal = -696969, maximal = 696969;

	do
	{
		scanf("%d", &n);
	}
	while(n > 500 || n < 1);
	
	while(i < n)
	{
		scanf("%d", &arr[i]);
		i++;
	}

	minmax(arr, n, &minimal, &maximal);

	printf("%d", minimal + maximal);

	return 0;
}

void minmax(int* arr, int size, int* min, int* max)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(*max > arr[i])
            *max = arr[i];
        if(*min < arr[i])
            *min = arr[i];
    }
}
