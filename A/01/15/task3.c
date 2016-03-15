#include <stdio.h>
#include <string.h>

struct occurance_t{
	long hash;
	int count;
	char words[4][200];
};

long hash(char *word);
int isRepeating(struct occurance_t *hashes, int hashPos, char *word);


int main(){
	char curWord[200];
	long int curHash;
	struct occurance_t hashes[3000] = {{0, 0, {{0}}}};
	struct occurance_t temp;
	int stop=0, hashCount=0, sort;
	int i=0, l;
	
	scanf("%s", curWord);
	curHash=hash(curWord);
	
	for(i=0; i<3000 && stop==0; i++){
		
		for(l=0; l<=i; l++){
			
			if(hashes[l].count==0){
				hashes[l].hash=curHash;
				strcpy(hashes[l].words[hashes[l].count], curWord);
				hashes[l].count++;
				
				if(hashes[l].count==4){
					stop=1;
					break;
				}
				
				hashCount++;
				
				break;
			}
			
			if(hashes[l].hash==curHash){
				
				if(isRepeating(hashes, l, curWord)==1){
					break;
				}
				
				strcpy(hashes[l].words[hashes[l].count], curWord);
				hashes[l].count++;
				
				if(hashes[l].count==4){
					stop=1;
					break;
				}
				
				break;
			}
		}
		if(stop==0){
			scanf("%s", curWord);
			curHash=hash(curWord);
		}
	}
	while(sort!=1) {
		sort = 1;
		for(i = 0; i<hashCount-1; i++) {
			if (hashes[i].hash>hashes[i+1].hash) {
				
				temp = hashes[i];
				hashes[i] = hashes[i+1];
                hashes[i+1]=temp;
				
				sort = 0;
			}
		}
	}
	for(i=0; i<hashCount; i++){
		if(hashes[i].count>1){
			
			printf("%ld ", hashes[i].hash);
			
			for(l=0; hashes[i].words[l][0]!=0 && l<4; l++){
				printf("%s ", hashes[i].words[l]);
			}
			printf("\n");
		}
	}
	return 0;
}

long hash(char *word){
	long res = 42;
	int len=strlen(word), i;
	for(i=1; i<=len; i++){
		res+=word[i-1] * i;
	}
	return res;
}

int isRepeating(struct occurance_t *hashes, int hashPos, char *word){
	int i;
	for(i=0; i<4; i++){
		if(strcmp(word, hashes[hashPos].words[i]) == 0){
			return 1;
		}
		if(word[0]=='\0'){
			break;
		}
	}
	return 0;
}
