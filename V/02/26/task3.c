#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* hop(int*);
int is_in_bound(int*, int, int*);

int main(){
    int* arr = (int*)malloc(sizeof(int)*50);
    int i, *p, k = 0, el;
    for(i = 0; i < 6; i++){
        scanf("%d", &arr[i]);
    }
    el = i;
    p = hop(&arr[0]);
    for(i = 1; i < 50; i++){
        if(is_in_bound(arr, 50, p) == 1 && p - &arr[0] < el){
            if(arr[p - &arr[0]] == 0){
                k = 1;
                break;
            } else p = hop(p);
        } else break;
    }
    printf("%d\n%d", k, i);
    free(arr);
    return 0;
}

int* hop(int *elem){
    return elem + *elem;
}

int is_in_bound(int *arr, int size, int *ptr){
    if(arr + 49 > ptr)
        return 1;
    return 0;
}
