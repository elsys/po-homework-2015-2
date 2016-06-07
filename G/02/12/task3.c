#include <stdio.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
    int arr[50];
    int lenght = 0;
    int counter = 0;
    int *ptr = &arr[0];

    while(scanf("%d", &arr[lenght]) != EOF || lenght < 50)
    {
        lenght ++;
    };
    for(;counter <= 50; counter++){

        ptr = hop(ptr);

        if(*ptr == 0){
            printf("1\n");
            printf("%d", counter);
	    break;
        };
        if(!is_in_bound(arr, lenght, ptr)){
            printf("0\n");
            printf("%d", counter);
	    break;
        };
        if(counter == 50 && *ptr != 0){
            printf("0\n");
            printf("%d", counter);
	    break;
        };
    };
return 0;
}

int* hop(int *elem){

    elem = elem + *elem;
return elem;
}

int is_in_bound(int *arr, int size, int *ptr){

    if(ptr >= arr && ptr < (arr+size)){
        return 1;
    };
return 0;
}
