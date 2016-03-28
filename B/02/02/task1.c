#include <stdio.h>


void minmax(int *arr, int size, int *min, int *max);


int main()
{
	int size, n, arr[500];
	static int min, max;
	scanf("%d", &n); 	
	size = --n;
	do{
		scanf("%d", &arr[n]);
		n--;
	}while(n>=0);
	min = arr[size];
	max = arr[size];
	for(n = 0; n<=size; n++)
		minmax(&arr[n], size, &min, &max);
	

	return 0; 
}

void minmax (int *arr, int size, int *min, int	*max)
{
	static int n = 1;
	int result;
	
		if (*min > *arr)
			*min = *arr;
		else if	(*max < *arr)
			*max = *arr;


		if(n==size)
		{
			result = *min + *max;
			printf("%d", result);
			
		}
		++n;
}

