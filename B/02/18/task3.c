#include <stdio.h>

int* hop(int *);
int is_in_bound(int *, int , int *);

int main()
{
    int array[50];
    int index = 0;
    int *temp;
    int find = 0;
    int elements = 0;
    
    for (index = 0; scanf("%d", &array[index]) != EOF; index++);
    
    elements = index;
    
    temp = hop(&array[0]);
    
    for (index = 1; index < 50; index++)
    {
        if (is_in_bound(array, 50, temp) == 1 && temp - &array[0] < elements)
        {
            if (array[temp - &array[0]] == 0)
            {
                find = 1;
                break;
            }
            
            else
            {
                temp = hop(temp);
            }
        }
        
        else
        {
            break;
        }
    }
    
    printf("%d\n%d", find, index);
    
    return 0;
}

int* hop(int *elem)
{   
    return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{
    if (arr + 49 > ptr)
    {   
        return 1;
    }
    
    return 0;   
}
