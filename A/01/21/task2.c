#include <stdio.h> 
#include <string.h>
#define MAX 2000

struct occurance_t{
	
	long int hash;
	int counter;
};

long hash(char *word);

int main(){
	
	struct occurance_t compare[MAX];
	char sentence[201];
	char replacer[8];
	int count = 0;
	int max = 0;
	long int maxhash = 0;
	
	for(int i = 0; i < max; i++){
		compare[i].hash = 0;
		compare[i].counter = 0;
	}
	
	strcpy(replacer, "vsmisal");

	while(strcmp(sentence, replacer) != 0){
		scanf("%s", sentence);
		if(strcmp(sentence, replacer) == 0){
			break;
		}
		else{
			compare[count].hash = hash(sentence);
			count ++;
		}
		
	}
	
	for(int i = 0; i < count; i++){
		for(int k = 1; k < count; k++){
			if(compare[i].hash == compare[k].hash){
				compare[i].counter ++;
				if(compare[i].hash > max){
					max = compare[i].counter;
					maxhash = compare[i].hash;
				}
			}
		}
	}
	
	printf("%d %ld", max, maxhash);
	
	return 0;
}

long hash(char *word){
	
	long int hash;
	
	hash = 42;
	
	for(int i = 0; i < strlen(word); i++){
		hash = hash + (word[i] * (i + 1));
	}
	
	return hash;
}
