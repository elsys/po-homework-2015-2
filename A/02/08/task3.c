#include <stdio.h>
#include <string.h>

int* hop(int *elem);
char is_in_bound(int *arr, int size, int *ptr);

int main()
{
    int arr[50], i = 0, arrSize;
    int* ptr = arr;
    char reachable = 0;

    while(scanf("%d", &arr[i]) && i < 50)
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

    printf("%d\n%d", reachable, i);

    return 0;
}

int* hop(int *elem){
    return (elem + *elem);
}

char is_in_bound(int *arr, int size, int *ptr){
    return (ptr < arr + size) ? 1 : 0;
}
