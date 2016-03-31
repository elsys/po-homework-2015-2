#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* hop(int *elem){
	return elem+*elem;
}

int is_in_bound(int *arr, int size, int *ptr){
	if(arr+49>ptr)
	return 1;
	return 0;
}

int main(){
	int arr[50];
	int i=0,*m,c=0,sym;
	do{
		scanf("%d",&arr[i]);
		i++;
	}while(i<6);
	sym=i;
	m=hop(&arr[0]);
	for(i=1;i<50;i++){
		if(is_in_bound(arr,50,m)==1&&m-&arr[0]<sym){
			if(arr[m-&arr[0]]==0){
				c=1;
				break;
			}
			else{
				m=hop(m);
			}
	}
		else{
			break;
		}
	}
	printf("%d\n%d", c, i);
	return 0;
}
