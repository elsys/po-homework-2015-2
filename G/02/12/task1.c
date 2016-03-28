#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);

int main(){

    int numbers[500];
    int length, count, min, max = 0, result;

    scanf("%d", &length);

    for(count = 0; count < length; count++){

        scanf("%d", &numbers[count]);

    }

    minmax(numbers, length, &min, &max);
    result = min + max;

    printf("%d", result);

    return 0;
}

void minmax(int *arr, int size, int *min, int *max){

    int count;

    *min = arr[0];

    for(count = 0; count < size; count++){

        if(arr[count] > max){

            *max = arr[count];

        }else if(arr[count] < min){

            *min = arr[count];

        }

    }

}
