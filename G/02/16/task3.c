#include <stdio.h>
#include <stdlib.h>

int* hop(int *elem);

int is_in_bound(int *arr, int size, int *ptr);

int main()
{

    int array[50];
    int hop_counter = 0;
    int *pointer = array;
    int size = 0;

    while(scanf("%d",&array[size]) != EOF || size < 50){

        size++;

    }

    while(*pointer != 0 && hop_counter < 50){

        pointer = hop(pointer);

        if(*pointer == 0){
            printf("1\n");
            printf("%d",hop_counter + 1);
        }




        if(is_in_bound(array,size,pointer) == 0){
            printf("0\n");
            printf("%d",hop_counter + 1);
            break;
        }

        if(hop_counter == 49){
            printf("0\n");
            printf("50");
        }

        hop_counter++;

    }




    return 0;
}


int* hop(int *elem){

    elem = elem + *elem;

    return elem;
}

int is_in_bound(int *arr, int size, int *ptr){

    if(ptr >= arr && ptr < &arr[size]){
        return 1;
    }

    return 0;
}
