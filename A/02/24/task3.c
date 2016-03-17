#include <stdio.h>
#include <string.h>
#define MAXSIZE 50

int* hop(int *elem);

char is_in_bound(int *arr, int size, int *ptr);

int main()
{
	int inp_array[MAXSIZE];
	int *ptr;
	int i = 0, valid = 0, length, counter_for_hops = 0;

	while((scanf("%d", &inp_array[i])) != EOF)
	{
		i++;
	}
	ptr = inp_array;
	
	length = i;

	while(is_in_bound(inp_array, length, ptr) && counter_for_hops < 50)
	{
		
		if(*ptr == 0)
		{
			valid = 0;
			break;
		}
		ptr = hop(ptr);

		counter_for_hops++;	

	}

	printf("%d\n%d",valid,counter_for_hops);


	return 0;
}

int *hop(int *elem)
{
	return(elem + *elem);
}


char is_in_bound(int *arr, int size, int *ptr)
{
	int i;
	int check = 0;
	for(i = 0; i < size; i++)
	{
		if(ptr == &arr[i])
		{
			check = 1;
			break;
		}
	}


	return check;
}