#include <stdio.h>
#include <string.h>

int* hop(int *elem);
char is_in_bound(int *arr, int size, int *ptr);

int main()
{
    int arr[50] = {0};
    int hopz,size;
    int* ptr = arr;
    int begin = 0;
    
    hopz = 0;
    while(scanf("%d", &arr[hopz]) != EOF && hopz < 50)
        hopz++;

    size = hopz;
    hopz = 0;
    while(hopz < 50 && is_in_bound(arr, size, ptr))
    {
        if(*ptr == 0)
        {
            begin = 1;
            break;
        }
        ptr = hop(ptr);
        hopz++;
    }

    printf("%d\n%d\n", begin, hopz);

    return 0;
}

int* hop(int *elem)
{
    return (elem + *elem);
}

char is_in_bound(int *arr, int size, int *ptr)

{
    if(ptr < arr + size)
        return 1;
    return 0;
}