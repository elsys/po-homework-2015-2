#include <stdio.h>


void minmax(int *arr,int size,int *min,int *max);

int main(){
	int i,max = 0,min = 0,size,final;
	int arr[ 500 ];
	scanf("%d",&size);	
	for(i = 0 ; i < size ; i++){
		scanf("%d",&arr[ i ]);	
	}
	minmax(arr,size,&min,&max);
	final = min + max;
	printf("%d\n",final);
return 0;
}

void minmax(int *arr,int size,int *min,int *max){
	int i;
	for(i = 0; i < size ;i++){
		if(arr[ i ] > *max)*max = arr[ i ];
		if(arr[ i ] < *min)*min = arr[ i ];
	}
}
