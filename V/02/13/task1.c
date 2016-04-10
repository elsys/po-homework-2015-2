#include <stdio.h>
#include <stdlib.h>
void minmax(int *arr, int size, int *min, int *max);

int main()
{
	int *in, n = 0, min = 0, max = 0;
	do
	{
		scanf("%d",&n);
	}while(n < 1 || n > 500);

	in = (int *) calloc(n, sizeof(int));

	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&in[i]);
	}
	
	minmax(in, n, &min, &max);
	printf("%d\n", min + max);

	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	*min = *arr;
	*max = *arr;
	
	for(int i = 0 ; i < size ; i++)
	{
		if(*(arr + i) < *min) *min = *(arr + i);
		if(*(arr + i) > *max) *max = *(arr + i);
	}
}
