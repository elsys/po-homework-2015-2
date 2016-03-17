#include <stdio.h>
#define MAX 50

int* hop(int*);
int is_in_bound(int*, int, int*);

int main(){

    int arr[MAX], i = 0, size, temp = 0, *ptr;

    while(scanf("%d", &arr[i]) != EOF){

        i++;
    }

    size = i;
    i = 0;
    ptr = &arr[0];

    while((is_in_bound(arr, size, ptr) == 1) && i < MAX){

        if(*ptr == 0){
            temp = 1;
            break;
        }

        i++;
        ptr = hop(ptr);
    }

    printf("%d \n%d", temp, i);


    return 0;
}

int is_in_bound(int *arr, int size, int *ptr){
    int i;

    for(i = 0; i < size; i++){

        if(ptr == &arr[i])
            return 1;
    }

    return 0;
}

int* hop(int *elem){

    return *elem + elem;
}
