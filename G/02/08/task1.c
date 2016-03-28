#include <stdio.h>

void minmax(int *arr, int size, int *min, int *max);
int main(){

int n;
int i=0,min=0,max=0;

do{

    scanf("%d",&n);

    i++;
}while(501<=n);

int arr[n];

for(i=0;i<n;i++){

    scanf("%d",&arr[i]);

}

minmax(arr,n,&min,&max);

   return 0;
}

void minmax(int *arr, int size, int *min, int *max){

int i,helper=0;

*min=arr[0];
*max=arr[0];

for(i=0;i<size;i++){

    helper=arr[i];
    if(*min>helper)*min=helper;

    if(*max<helper)*max=helper;

}
printf("%d",(*min+*max));
helper=(*min)+(*max);
}

