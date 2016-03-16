#include <stdio.h>

void minmax(int *, int, int *, int *);
int main()
{
    int arr[500];
    int size, min, max, sum = 0;
    int counter;

    scanf("%d",&size);
    for(counter = 0; counter < size; counter++)
    {
        scanf("%d",&arr[counter]);
    }
    max = arr[0];
    min = arr[0];
    minmax(arr ,size ,&min ,&max);
    sum = min + max;
    printf("%d\n",sum);
    return 0;
}
void minmax(int *arr, int size, int *min, int *max)
{
    int counter;
    for(counter = 0; counter < size; counter++)
    {
        if(arr[counter] > *max)
        {
            *max = arr[counter];
        }
        if(arr[counter] < *min)
        {
            *min = arr[counter];
        }
    }
}
