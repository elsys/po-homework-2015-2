#include <stdio.h>
#include <string.h>

void minmax(int *,int , int *,int *);

int main()
{
    int n,i,arr[500],min,max;

    scanf("%d",&n);

    for(i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }

    min = arr[0];

    max = arr[0];

    minmax(arr, n, &min,&max);


    return 0;
}

void minmax(int *arr,int size,int *min,int *max)
{
    int i;
    int sum = 0;

    for(i = 0; i < size; i++)
    {
        if(*min > arr[i])
        {
            *min = arr[i];
        }
        if(*max < arr[i])
        {
            *max = arr[i];
        }
    }

    sum = *min + *max;

     printf("%d",sum);
}
