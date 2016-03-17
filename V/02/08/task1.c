#include <stdio.h>
void minmax(int *arr, int size, int *min, int *max);

int main()
{
	
	int size=0,min=0,max=0, arr[500]={0};

	scanf("%d",&size);
	if (size==0)
	{
		return 666;
	}
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
	}


	minmax(arr,size,&min,&max);
	printf("%d", (min+max) );
	return 0;
}

void minmax(int *arr, int size, int *min, int *max){

	*min=arr[0];
	*max=arr[0];

	for (int i = 1; i < size; ++i)
	{
		if (*max<arr[i])
		{
			*max=arr[i];
		}

		if (*min>arr[i])
		{
			*min=arr[i];
		}
	}
}
