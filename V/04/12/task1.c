#include <stdio.h>
#include <string.h>

int valid_isbn();
int check_sum();


int main(){
	char isbnnum[20];
	char check[6];
	// char bank1[10] = "Bluebridge";
	// char bank2[12] = "Alyson Books";
	// char bank3[28] = "FUNimation Productions, Ltd.";
	// char bank4[13] = "Pyramid Books";
	int last = 0;
	scanf("%s",isbnnum);
	// printf("%d",valid_isbn(isbnnum));
	if(valid_isbn(isbnnum)){
		printf("1");		
		for(unsigned int i = 0;i < strlen(isbnnum); i++){
			if(isbnnum[i]=='-'){
				for(int k = 0; k < i - last ; k++){// 012-456-8910-
					check[k] = isbnnum[last + k];
				}
				last = i + 1;
				// printf("\n%s\n",check );
				// char checkv2[5] =  "55583";
				// printf("%d\n",strcmp(checkv2,check));
				if(!strcmp(check,"933346")){
					printf("Bluebridge");
				}else if(!strcmp(check, "55583")){
					printf("Alyson Books");
				}else if(!strcmp(check, "4210")){
					printf("FUNimation Productions, Ltd.");
				}else if(!strcmp(check,"01")){
					printf("Pyramid Books");
				}
			}
		}
	}else{
		printf("0");
	}
	return 0;
}

int valid_isbn(char isbnnum[]){
	
	char start[3] = {'9','7','8'};
	char start1[3] = {'9' , '7' , '9'};
	int check = 0;

	for(int i = 0; i < 3;i++){
		if(isbnnum[i] == start[i] || isbnnum[i] == start1[i]){

		}else{
			return 0;
		}
	}
	for(unsigned int i = 0; i < strlen(isbnnum); i++){
		if(isbnnum[i] >= '0' && isbnnum[i] <= '9'){
			check++;
		}
	}
	if(check != 13){
		return 0;
	}
	if(check_sum){
		return 1;
	}else{
		return 0;
	}
}

int check_sum(char isbnnum[]){
	int numbers[13];
	unsigned int len = strlen(isbnnum) - 2;
	for(unsigned int i = 0, k = 0; i < len; i++){
		if(isbnnum[i] >= '0' && isbnnum[i] <= '9'){
			numbers[k] = isbnnum[i] - '0';
			k++;
		}
	}

	int sum = 0, cur_sum = 0;
	for(int i = 11; i >= 0; i--){
		if( i % 2 != 0){
			cur_sum = 2 * numbers[i];
			if(cur_sum > 9){
				cur_sum = cur_sum % 10 + 1;
			}
		}else{
			cur_sum = numbers[i];
		}
		sum += cur_sum;
	}
	// while(len >= 0){
	// 	if(len % 2 == 0){
	// 		cur_sum = 2 * (isbnnum[len] - '0');
	// 		if(cur_sum > 9){
	// 			cur_sum = cur_sum % 10 + 1; 
	// 		}
	// 	}else{
	// 		cur_sum = isbnnum[len] - '0';
	// 	}
	// 	len--;
	// 	sum += cur_sum;
	// }
	sum = 10 - (sum % 10);
	if(sum == numbers[12]){
		return 1;
	}else{
		return 0;
	}
}
