#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{

    int arr[100];
    int n, i, min = 0, max = 0, result;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    minmax(arr, n, &min, &max);
    result = max + min;

    printf("%d", result);

    return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
    int i;
    *max = arr[0];
    *min = arr[0];

    for(i = 0; i < size; i++)
    {
        if(*max < arr[i])
            *max = arr[i];
        if(*min > arr[i])
            *min = arr[i];
    }

    return 0;
}
