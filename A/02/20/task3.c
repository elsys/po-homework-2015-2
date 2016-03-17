#include <stdio.h>
#define MAX 50

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
	int arr[MAX];
	int size=0;
	int *elem = NULL;
	int hops = 0;
	int out=0;

    while(scanf("%d", &arr[size])!=EOF || size < 50)
    {
        size++;
    }



	elem = &arr[0];

	for(hops =0; hops<MAX; hops++)
	{
		if(is_in_bound(arr, size, elem) == 0)
		{
			break;
		}
		if(*elem == 0)
		{
			out=1;
		}
		elem = hop(elem);
		break;
	}
	printf("%d\n", out);
	printf("%d\n", hops);
	return 0;

}


int *hop(int *elem)
{

	return elem + *elem;
}



int is_in_bound(int *arr, int size, int *ptr)
{

	for (int i = 0; i < size; ++i)
	{
		if(ptr == &arr[i])
		{
			
			return 1;
		}
	}
	return 0;
}
