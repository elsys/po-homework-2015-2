#include <stdio.h>
#include <string.h>

long hash(char* word);

struct occurance_t{
	long hash;
	int ocNumber;
};

int main(){
	char word[201];
	struct occurance_t words[3000];
	struct occurance_t mostCommon;
	int i;

	for(i = 0; i < 3000; i++){
		words[i].hash = 0;
		words[i].ocNumber = 0;
	}

	i = 0;
	
	while(scanf("%s", word) && strcmp(word, "vsmisal") != 0 && i < 3000){
		i = 0;
		
		while(1){
			if(hash(word) != words[i].hash){
				if(words[i].hash != 0)
					i++;
				else{
					words[i].hash = hash(word);
					words[i].ocNumber = 1;
					break;
				}
			}
			else{
				words[i].ocNumber++;
				break;
			}
		}		
	}

	mostCommon.ocNumber = 0;
	for(i = 0; words[i].hash != 0; i++){
		if(words[i].ocNumber > mostCommon.ocNumber){
			mostCommon.hash = words[i].hash;
			mostCommon.ocNumber = words[i].ocNumber;
		}
	}

	printf("%d %li", mostCommon.ocNumber, mostCommon.hash);

	return 0;
}

long hash(char* word){
	int i;																																																																																																																																																																																																																					
	long hashed = 42;
	
	for(i = 0; i < strlen(word); i++){
		hashed += word[i]*(i+1);
	}

	return hashed;
}