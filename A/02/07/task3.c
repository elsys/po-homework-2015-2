#include <stdio.h>
#include <stdlib.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
    int *point;
    int i, size;
    int arr[50];
    for(i = 0; arr[i] != EOF; i++)
    {
        scanf("%d", &arr[i]);
        if(i == 50)
            break;
    }

    point = arr;
    size = i;
    for(i = 0; i < 50 && is_in_bound(arr, size, point) != 0;)
    {
        if(*point == 0)
        {
            printf("1");
            printf("\n%d", i);
            return 0;
        }
        point = hop(point);
        i++;
    }

    printf("0");
    if(is_in_bound(arr, size, point) == 0)
        printf("\n%d", i-1);
    else
        printf("\n%d", i);

    return 0;
}
int* hop(int *elem)
{
    return (elem + *elem);
}

int is_in_bound(int *arr, int size, int *ptr)
{
    if(ptr < arr + size)
    {
        return 1;
    }

    return 0;
}
