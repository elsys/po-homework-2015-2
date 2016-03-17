#include <stdio.h>

void minmax(int *, int , int *, int *);

int main()
{
    int array[500];
    int size = 0;
    int index = 0;
    int min = 0;
    int max = 0;
    int sum = 0;
    
    scanf("%d", &size);
    
    for (index = 0; index < size; index++)
    {
        scanf("%d", &array[index]);
    }
    
    minmax(array, size, &min, &max);
    
    sum = max + min;
    
    printf("%d", sum);
      
    return 0;
}

void minmax(int *arr, int size, int *min, int *max)
{
    int index = 0;
   
    *min = arr[0];
    *max = arr[0];
    
    for (index = 0; index < size; index++)
    {
        if (*min > arr[index])
        {
            *min = arr[index]; 
        }
        
        if (*max < arr[index])
        {
            *max = arr[index];
        }
    }
}
