#include <stdio.h>
#include <stdlib.h>
int *hop(int *elem);
int is_in_bound(int *arr, int size, int *elem);

int main()
{
    int arr[50];
    int input;
    int size = 0;
    int output = 0;
    int *elem = NULL;
    int hops = 0;
    while(scanf("%d", &input) == EOF || size < 50)
    {
        arr[size] = input;
        size++;
    }
    elem = &arr[0];
    while(hops<50)
    {
        if(is_in_bound(arr, size, elem)==0)
        {
            break;
        }
        if(*elem == 0)
        {
            output = 1;
            break;
        }
        elem = hop(elem);
        hops++;
    }
    printf("\n%d", output);
    printf("\n%d", hops);
    return 0;
}

int *hop(int *elem)
{
    return (elem + *elem);
}

int is_in_bound(int *arr, int size, int *elem)
{
	if(elem >= arr && elem < arr+size)
    {
		return 1;
	}
	return 0;
}
