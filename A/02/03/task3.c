#include <stdio.h>
#include <string.h>

 
int* hop(int *elem) 
{
    return elem + (*elem);
}
 
int is_in_bound(int *arr,int size,int *ptr) 
{ int i=0;
    while(i<size)
    {
        if (*ptr== *(arr+i) )
        {
            return 1;
        }
      i++;
    }
 
    return 0;
}
 
int main() 
{int arr[50];
    int num;
    int size = 0;
    int hops = 0;
    int found = 0;
    int currPos = 0;
    int *ptr = arr;
    while (scanf("%d", &num) != EOF) 
    {
        arr[size]=num;size++;
    }

    while (hops < 50)
    {
        if (!is_in_bound(arr, size, ptr)) 
        {break;}
        ptr = hop(&arr[currPos]);
     
        if (arr[currPos] == 0) 
        {
            
            found = 1;
            break;
        }
        currPos=currPos+arr[currPos];
        hops++;
    }
 
    printf("%d\n", found);
    printf("%d\n", hops);
 
    return 0;
}
