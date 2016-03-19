#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max)
{
	int i;
	*max = arr[0];
	*min = arr[0];
	for(i = 1;i < size;i++)
	{
		if(*max < arr[i])
		{
			*max = arr[i];
		}
		if(*min > arr[i])
		{
			*min = arr[i];
		}
	}
}

int main()
{
int n, min, max, i = 0;
scanf("%d", &n);
	if (n<=500 && n>=1)
	{
		int arr[n];
		while(i<n)
		{
				scanf("%d", &arr[i]);
				i++;
		}
		minmax(arr, n, &min, &max);
		printf("%d", min+max);
	}
	else
{
return 0;
}
}
