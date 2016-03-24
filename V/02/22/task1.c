#include <stdio.h>

void minmax(int *arr,int size,int *min,int *max);

int main(){
	int i,n,min,max,sum;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",arr[i]);
	}
	minmax(arr,n,&min,&max);
	sum=min+max;
	printf("%d",sum);


	return 0;
}

void minmax(int *arr,int size,int *min,int *max){
	int i=0;
	*min=arr[i];
	i++;
	if(arr[i]>*min)
		*max=arr[i];
	else{
		*max=*min
		*min=arr[i];
	}
	i++;
	for(;i<size;i++){
		if(arr[i]>*max)
			*max=arr[i];
		if(arr[i]<*min)
			*min=arr[i];
	}
}

