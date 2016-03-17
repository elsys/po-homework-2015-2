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
	struct occurance_t array[3000];
	int max_words = 0, count = 0, flag = 1;
	char word[200] = {0};
	// char st_word[200] = {0};
	for(int i = 0; i < 3000 && max_words < 4;i++){
		scanf("%s",word);
		for(int k = 0;k < count; k++){//don't forget to make count++
			if(array[k].hash == hash(word)){
				if(!strcmp_line(word,array[k])){
					// printf("I am here\n");
					flag = 0;
					for(unsigned int j = 0; j < strlen(word); j++){
						array[k].same_hash[array[k].times][j] = word[j];
					}
					array[k].times++;
					if(max_words < array[k].times){
						max_words = array[k].times;
					}
				}
			}
		}
		if(flag){
			array[count].times++;
			array[count].hash = hash(word);
			for(unsigned int j = 0; j < strlen(word); j++){
				array[count].same_hash[0][j] = word[j];
			}
			count++;
		}
	}
	for(int i = 0; i < count; i++){
		for(int k = 0; k < count - i - 1; k++){
			if(array[i].times < array[k].times){
				struct occurance_t swap  = array[k];
				array[k] = array[i];
				array[i] = swap;
			}
		}
	}
	// count = 0;
	for(count = 0; array[count].times > 1; count++);
	for(int i = 0; i < count ; i++){
		for(int k = 0; k < count - i - 1; k++){
			if(array[i].hash < array[k].hash){
				struct occurance_t swap = array[k];
				array[k] = array[i];
				array[i] = swap; 
			}
		}
	}
	for(int i = 0; i < count;i++){
		printf("[%ld]",array[i].hash);
		for(int k = 0; k < array[i].times ; k++){
			for(int j = 0; j < strlen(array[i].same_hash[k]);j++){
				printf("%c",array[k].same_hash[k][j]);
			}
		}
		printf("\n");
	}

	return 0;
}



long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}


int strcmp_line(char word[],struct occurance_t occ_word){
	for(int i = 0; i < occ_word.times; i++){
		if(strlen(word) != strlen(occ_word.same_hash[i])){
			// printf("return 0\n");
			// printf("%d %d\n",strlen(word),strlen(occ_word.same_hash[i]));
			return 0;
		}else{
			// printf("- >%s\n",word );
			for(unsigned int k = 0;k < strlen(word);k++){
				if(word[k] != occ_word.same_hash[i][k]){
					// printf("return 0 as\n");
					return 0;
				}
			}
		}
	}
	// printf("return 1\n");
	return 1;
}