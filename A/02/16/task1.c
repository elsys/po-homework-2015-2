#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int size);

int main()
{
    int arr[500] = {0};
    int size = 0;
    int temp;
    while(size<=0 || size > 500)
    {
        scanf("%d", &size);
    }
    temp = 0;
    while(temp<size)
    {
        scanf("%d", &arr[temp]);
        temp++;
    }
    minmax(arr, size);
    return 0;
}

void minmax(int *arr, int size)
{
    int swap;
    int counter2 = 0;
    int counter3 = 0;
    int sum = 0;
    while(counter2 < (size - 1))
    {
        while(counter3 < (size - counter2 - 1))
        {
            if(arr[counter3] > arr[counter3+1])
            {
                swap = arr[counter3];
                arr[counter3] = arr[counter3+1];
                arr[counter3+1] = swap;
            }
            counter3++;
        }
        counter2++;
        counter3 = 0;
    }
    counter3 = 0;
    sum = arr[0] + arr[size-1];
    printf("\n%d", sum);
}
