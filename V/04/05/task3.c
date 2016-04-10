#include <stdio.h>
#include <string.h>

int takeDigits(char a[], int nums[]);
int check_result(unsigned int len,int result, int nums[]);


int main(){
	char a[10];
	int result,check = 0;
	scanf("%s",a);
	scanf("%d",&result);
	unsigned int len = strlen(a);
	int nums[len];
	takeDigits(a,nums);
}

int takeDigits(char a[], int nums[]){
	for(unsigned int i= 0; i< strlen(a); i++){
		nums[i] = a[i] -'0';
 	}
}


int check_result(unsigned int len,int result, int nums[]){
	int check = 0;
	for(unsigned int i = 0; i < len; i++){
		check+=nums[i];
	}
	if(result = check){
		return 1;
	}else{
		check_result();
	}
}
