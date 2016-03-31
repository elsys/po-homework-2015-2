#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int size, int *min, int *max);
int main(){

    int result , size = 0 , min = 0 , max = 0 , arr[500] , counter = 0 ;

    scanf("%d",&size);

for(counter = 0 ; counter < size ; counter ++){

    scanf("%d",&arr[counter]);

}

minmax(arr , size , &min , &max);

result = min + max ;

printf("%d",result);


return 0 ;
}

void minmax(int *arr, int size, int *min, int *max) {
int counter ;

for(counter = 0 ; counter < size ; counter ++) {
    if(*min > arr[counter])
        *min = arr[counter];

    if(*max < arr[counter])
       *max = arr[counter];

}
}
