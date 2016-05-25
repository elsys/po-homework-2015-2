#include <stdio.h>
#include <stdlib.h>


int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);
int main()
{

    int arr[50];
    int *ptr = &arr[0];
    int size = 0;

    while(scanf("%d",&arr[size]) != EOF || size < 50)
    {

        size ++;
    }


    int j;

    for(j=1; j <=50 ||  *ptr == 0; j++)
    {

        ptr=hop(ptr);
        if(*ptr == 0 )
        {
            printf("1\n");

            printf("%d",j);

            break;
        }
        if(!is_in_bound(arr,size,ptr))
        {
            printf("0\n");
            printf("%d",j);

            break;
        }

        if(j==50 && *ptr != 0)
        {

            printf("0\n");
            printf("%d",j);

        }

    }
    return 0;
}

int* hop(int *elem)
{

    elem = elem + *elem;

    return elem;
}

int is_in_bound(int *arr, int size, int *ptr)
{


    if(ptr >= arr && ptr < (arr+size))
        return 1;

    return 0;
}



