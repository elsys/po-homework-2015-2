#include <stdio.h>
#include <stdlib.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
    int len = 0, count = 0, p = 0, jumps = 0;
    int *result;
    char str[3], c = '\0';
    int array[50];


    while(c != EOF)
    {
        c = getchar();
        if(c != ' ' && c != '\n')
        {
            str[p] = c;
            p++;
        }
        else
        {
            str[p] = '\0';
            p = 0;
            array[len]=atoi(str);
            len++;
        }

    }


    result = &array[0];

    int check = 1;

    while(jumps < 50 && *result != 0 && check == 1)
    {

        result = hop(result);
        check = is_in_bound(array, len, result);

            jumps++;

    }
    if(jumps == 50)
    {
        check = 0;
    }
    printf("%d\n", check);
    printf("%d", jumps);

    return 0;
}
int* hop(int *elem)
{
    return (elem + *elem);
}

int is_in_bound(int *arr, int size, int *ptr)
{
     int i;
     for(i = 0; i < size; i++)
     {
         if(ptr == (arr + i))
         {
             return 1;
         }

     }
     return 0;
}

