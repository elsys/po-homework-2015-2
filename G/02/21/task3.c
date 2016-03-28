#include <stdio.h>

#define MAXIMUM_ELEMENTS 50
#define MAX_HOPS 50

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
	int array[MAXIMUM_ELEMENTS];
	int size = 0;
	int hops=0;
	int has_road = 0;

	while(scanf("%d",&array[size]) != EOF)
	{
		size++;
	}

	int i = 0;

	int *element = array;
	
	for (i = 0; i < MAX_HOPS; ++i)
	{
		if(*element == 0)
		{
			has_road = 1;
			break;
		}
		else if(!is_in_bound(array, size, element))
		{
			break;
		}
		else 
		{
			element = hop(element);
			hops++;
		}
	}

	printf("%d\n%d", has_road,hops);

	return 0;
}

int* hop(int *elem)
{
	int *new_element = elem + *elem;
	return new_element;
}

int is_in_bound(int *arr, int size, int *ptr)
{
	if(arr > ptr || (arr+size-1) < ptr)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
