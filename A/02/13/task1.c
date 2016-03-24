#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int size, int *min, int *max);

int main()
{
    int numbers[500];
    int i, size, sum;
    int min, max;

    scanf("%d", &size);

    for(i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }

    minmax(numbers, size, &min, &max);

    sum = min + max;
    printf("%d", sum);
    return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
    int p;

    *max = arr[0];
    *min = arr[0];



        for(p = 0; p < size; p++)
        {
            if(*max > arr[p])
            {
              *max = arr[p];

            }
            if(*min < arr[p])
            {
                *min = arr[p];
            }
        }

}

