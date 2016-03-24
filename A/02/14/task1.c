#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 501

void minmax(int *arr, int size, int *min, int *max);

int main()
{
    int min, max, lenght=0, i=0, sum=0;
    int arr[MAXLEN];

    scanf("%d",&lenght);

    while(i<lenght)
    {
            scanf("%d",&arr[i]);
            i++;
    }

    minmax(arr, lenght, &min, &max);

    sum=max+min;

    printf("%d\n",sum);

    return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
    int i;
    *min=2147483647;
    *max=-2147483648;

    for(i=0; i<size;i++)
    {
        if(arr[i]>*max)*max=arr[i];
        if(arr[i]<*min)*min=arr[i];
    }
}
