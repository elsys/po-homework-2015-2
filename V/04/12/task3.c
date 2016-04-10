#include <stdio.h>
#include <string.h>

int takeDigits(char a[], int nums[]);
int check_result(unsigned int len, int nums[]);
int result;

int main(){
	char a[10];
	// int check = 0;
	scanf("%s",a);
	scanf("%d",&result);
	unsigned int len = strlen(a);
	int nums[len * 2];
	takeDigits(a,nums);
	permute(nums,0,len);
	// do{
	// 	for(int i = 0;i < strlen(a); i++){
	// 		for(int k = 0;k < strlen(a);k++){

	// 		}
	// 	}
	// }while(check != result);
}

int takeDigits(char a[], int nums[]){
	for(unsigned int i= 0; i< strlen(a); i++){
		nums[i] = a[i] -'0';
 	}
 	for(unsigned int i= strlen(a); i < 2 * strlen(a); i++){
		nums[i] = a[i] -'0' * (-1);
 	}
}

void permute(int array[],int i, int len){
	if(len == i){
		return -1;
	}else{
		int j = i;
		for(j = i; j < len * 2;j++){
			int swap = array[i];
			array[i] = array[j];
			array[j] = swap;
			check_result(len,array);
			permute(array,i+1,len);
			// printf("KAKA\n");
			// break;
		}
	}
}

int check_result(unsigned int len, int nums[]){
	for(int i = 0; i < len; i++){
		for(int k = i; k < len; k++){
			if(nums[i] == -1 * nums[k] || nums[k] == -1 * nums[i]){
				return 0;
			}
		}
	}
	int check = 0;
	for(int i = 0; i < len;i++){
		check+= nums[i];
		printf("s %d\n",check);

		break;
	}
	if (check == result){
		for (int i = 0; i < len; ++i)
		{
			if(i = 0 && nums[i] > 0){
				printf("%d ",nums[i] );
			}else if(nums[0] < 0){
				return;
			}
			if(nums[i] > 0){
				printf( "+ %d",nums[i]);
			}else{
				printf("- %d",nums[i]);
			}
		}
	}
}