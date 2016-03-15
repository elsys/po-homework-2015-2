#include <stdio.h>
#include <string.h>

int* hop(int *elem);
char is_in_bound(int *arr, int size, int *ptr);

int main()
{
    int arr[50], i, arrSize;
    int* ptr = arr;
    int reachable = 0;
    
    i = 0;
    while(scanf("%d", &arr[i]) != EOF && i < 50)
        i++;

    arrSize = i;
    i = 0;
    while(i < 50 && is_in_bound(arr, arrSize, ptr)){
        if(*ptr == 0){
            reachable = 1;
            break;
        }
        ptr = hop(ptr);
        i++;
    }

    printf("%d %d", reachable, i);

    return 0;
}

int* hop(int *elem){
    return (elem + *elem);
}

char is_in_bound(int *arr, int size, int *ptr){

    if(ptr < arr + size)
        return 1;
    return 0;
}
