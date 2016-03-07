#include <stdio.h>
#include <string.h>

struct occurance_t{
	long hash;
	int count;
};

long hash(char *word);

int main(){
	char curWord[200];
	long int curHash;
	struct occurance_t hashes[3000] = {{0, 0}};
	int maxIndex=0;
	int i=0, l;
	scanf("%s", curWord);
	curHash=hash(curWord);
	for(i=0; i<3000 && strcmp(curWord, "vsmisal")!=0; i++){
		if(strlen(curWord)>200){
			printf("sakun: Word is longer than 200 ");
			return 0;
		}
		for(l=0; l<=i; l++){
			if(hashes[l].count==0){
				hashes[l].hash=curHash;
				hashes[l].count++;
				break;
			}
			else if(hashes[l].hash==curHash){
				hashes[l].count++;
				break;
			}
		}
		scanf("%s", curWord);
		curHash=hash(curWord);
	}
	
	for(l=0; l<i; l++){
		if(hashes[l].count>hashes[maxIndex].count){
			maxIndex=l;
		}
	}
	
	printf("%d %ld", hashes[maxIndex].count, hashes[maxIndex].hash);
	
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
