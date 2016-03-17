#include <stdio.h>

void minimax(int *, int, int *, int *);

int main()
{
	int arr[500], s, minimum, maximum, c;
	int sum;

	scanf("%d", &s);
	if(s>0 && s<500)
	{
		for(c=0; c<s; c++)
		{
			scanf("%d", &arr[c]);
		}
	}

	minimax(arr,s,&minimum,&maximum);

	sum=maximum+minimum;

	printf("%d\n", sum);

	return 0;
}

void minimax(int *arr, int s, int *minimum, int *maximum)
{
	int j;

	for(j=0; j<s; j++)
	{
		if(arr[j]>*maximum)
		{
			*maximum=arr[j];
		}
		if(arr[j] < *minimum)
		{
			*minimum=arr[j];
		}
	}
}
