#include <stdio.h>
#include <string.h>


void printer(int array[], int len, int sum);
int check_sum(int array[], int sum, int position, int len);
int array_sum(int array[], int len);
int result_ans = 1;

int main(){
	char input[10];
	int sum;
	scanf("%s",input);
	scanf("%d", &sum);
	int intput[strlen(input)];
	for(unsigned int i = 0; i < strlen(input);i++){
		intput[i] = input[i] - '0';
	}
	check_sum(intput, sum, 1, strlen(input));
	if(result_ans){
		printf("-1");
	}
	return 0;
}


int check_sum(int array[], int sum, int position, int len){
	if(position >= len){
		return 0;
	}
	int flag = 0;
	int cur_rotation[len];
	//COPY
	for(int i = 0; i < len; i++){
		cur_rotation[i] = array[i];
	}


	for(int i = 0; i < 2; i++){
		if(i != 0){
			array[position] *= -1;			
		}
		// printf("%d %d %d\n",array[0],array[1],array[2] );
		// CHECK FOR COPY
		for(int k = 0; k < len; k++){
			if(cur_rotation[k] != array[k]){
				flag = 1;
			}
		}
		if(flag){	
			if(array_sum(array, len) == sum){
				printer(array, len, sum);
			}
			check_sum(array, sum, position + 1,len);
		}else{
			check_sum(array, sum, position + 1,len);			
		}
	}
}

int array_sum(int array[], int len){
	int sum = 0;
	for(int i = 0; i < len; i++){
		sum += array[i];
	}
	return sum;
}

void printer(int array[], int len, int sum){
	printf("%d",array[0]);
	for(int i = 1;i < len; i++){
		if(array[i] > 0){
			printf("+");
			printf("%d", array[i]);
		}else{
			printf("%d", array[i]);
		}
	}
	printf("=%d",sum);
	result_ans = 0;
}