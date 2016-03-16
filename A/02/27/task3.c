#include <stdio.h>

int* hop(int*);
int is_in_bound(int*, int, int*);
int hops = 0;

int main()
{
	int arr[50], i = 0, j = 0;
	while(scanf("%d", &arr[i]) != EOF)
	{
		i++;
	}
	while(is_in_bound(arr, i, hop(&arr[j])) && hops < 50)
	{
		hops++;
		if(*hop(&arr[j]) == 0)
		{
			printf("1");
		 	break;
		}
		else j = j + arr[j];
	}
	if(!is_in_bound(arr, i, hop(&arr[j])))
	{
		printf("0");
		hops++;
	}
	else if(hops == 50) printf("0");
	printf("\n%d", hops);
	return 0;
}

int* hop(int *elem)
{
	return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
	for(int i = 0; i < size; i++)
	{
		if(ptr == &arr[i])
			return 1;
	}
	return 0;
}
