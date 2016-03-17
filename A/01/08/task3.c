#include <stdio.h>
#include <string.h>

long hash(char* word);

struct occurance_t{
	long hash;
	char collisions[4][201];
};

int main(){
	char word[201];
	struct occurance_t words[3000];
	int i, j;

	for(i = 0; i < 3000; i++){
		words[i].hash = 0;
		for(j = 0; j < 4; j++){
			words[i].collisions[j][0] = 0;
		}
	}


	while(1){
		scanf("%s", word);
		i = 0;

		while(words[i].hash != 0 && i < 3000){
			if(hash(word) == words[i].hash){

				for(j = 0; words[i].collisions[j][0] != 0 && j < 4 && strcmp(word, words[i].collisions[j]) != 0; j++);
				if(strcmp(word, words[i].collisions[j]) != 0)
					strcpy(words[i].collisions[j], word);
                break;
			}
			i++;
		}
		if(j == 3)
            break;
		if(words[i].hash == 0 && i < 3000){
			words[i].hash = hash(word);
			strcpy(words[i].collisions[0], word);
		}
	}

	int strSize;
	for(strSize = 0; words[strSize].hash != 0; strSize++);

	for(i = 0; i < (strSize-1); i++){
		for(j = 0; j < (strSize-i-1); j++){
			if(words[j].hash > words[j+1].hash){
				struct occurance_t temp;
				temp.hash = words[j].hash;
				for(int k = 0; k < 4 && words[j].collisions[k] != 0; k++)
					strcpy(temp.collisions[k], words[j].collisions[k]);
				
				words[j].hash = words[j+1].hash;
				for(int k = 0; k < 4 && words[j+1].collisions[k] != 0; k++)
					strcpy(words[j].collisions[k], words[j+1].collisions[k]);
				
				words[j+1].hash = temp.hash;
				for(int k = 0; k < 4 && temp.collisions[k] != 0; k++)
					strcpy(words[j+1].collisions[k], temp.collisions[k]);
			}
		}
	}

	for(i = 0; i < strSize; i++){
		if(words[i].collisions[1][0] != 0){
			printf("%li", words[i].hash);
			for(j = 0; j < 4 && words[i].collisions[j][0] != 0; j++){
				printf(" %s", words[i].collisions[j]);
			}
			printf(" ");
		}
	}
	printf("\b");

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
