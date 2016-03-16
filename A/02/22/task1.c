#include <stdio.h>

void minmax(int *, int , int *, int *);

int main()
{
	int arr[500];
	int size;
	int min, max;
	int n, i=0;
	scanf("%d",&n);
	size=n;
	while(i!=n)
	{
		scanf("%d",&arr[i]);
		i++;
	}
	minmax(arr, size, &min, &max);
	printf("%d", min+max);
	return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
	*min=arr[0];
	*max=arr[0];
	for(int i=0; i!=size; i++)
	{
		if(*min>arr[i])
		{			
			*min=arr[i];
		}
		if(*max<arr[i])
		{
			*max=arr[i];
		}
	}
}