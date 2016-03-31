#include <stdio.h>
#include <string.h>


struct occurance_t{
	long hash;
	int times;
	char same_hash[4][200];
};

long hash(char word[]);
int strcmp_line(char word[],struct occurance_t occ_word);


int main(){
	struct occurance_t words[3000];
	int count_inp = 0,flag = 0;
	char input[200];
	for(int i = 0;i < 3000 && flag != 2; i++){
		flag = 0;
		do{
			scanf("%s",input);
		}while(strlen(input) > 200);
		for(int k = 0;k < count_inp; k++){
			if(hash(input) == words[k].hash){
				if(strncmp(&input[0] , &words[k].same_hash[words[k].times - 1][0] , strlen(input) )){
					//printf("%d",strncmp(&input[0], &words[k].same_hash[words[k].times - 1][0],strlen(input)));

					for(unsigned int j = 0; j < strlen(input);j++){
						words[k].same_hash[words[k].times][j] = input[j];
					}
					if(words[k].times == 3){
						words[k].times++;
						flag  = 2;
					}else{
						flag = 1;
						words[k].times++;
					}
				}
			}
		}
		if(!flag){
			for(unsigned int j = 0; j < strlen(input);j++){
				words[count_inp].same_hash[0][j] = input[j];
			}
			words[count_inp].times++;
			words[count_inp].hash = hash(input);
			count_inp++;
		}
	}



	//SORT
	for(int i = 0; i  < count_inp; i++){
		for(int x = i; x < count_inp; x++){
			if(words[i].hash > words[x].hash){
				struct occurance_t swap = words[x];
				words[x] = words[i];
				words[i] = swap;
			}
		}
	}



	//PRINT
	for(int i = 0; i < count_inp; i++){
		if(words[i].times > 1){
			printf("%ld",words[i].hash);
			for(int k  = 0; k < words[i].times;k++){
				printf(" ");
				for(unsigned int a = 0; a < strlen(words[i].same_hash[k]);a++){
					printf("%c",words[i].same_hash[k][a]);
				}
			}
			printf("\n");
		}
	}
}



long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}
