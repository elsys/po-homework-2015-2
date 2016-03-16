#include <stdio.h>

void minmax(int *arr,int size);
int main()
{
    int sum=0;
    int arr[200], i=0,size;
    scanf("%d\n",&size);
    for(i=1;i<=size;i++)
        scanf("%d",&arr[i]);
         minmax(arr,size);
         sum =arr[1]+arr[size];
         printf("%d",sum);


    return 0;
}
void minmax(int *arr,int size){
    int c,d;
    for ( c = 1 ; c <=  size  ; c++){
        for ( d = 1 ; d <= size - c ; d++){
            if (arr[d] < arr[d+1]){
                    int swap = arr[d];
                    arr[d] = arr[d+1];
                    arr[d+1]= swap;
            }
        }
    }

}
