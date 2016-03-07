#include <stdio.h>
#include <string.h>
#define start 42

long hash(char *word) {
        long num = start;
        for(int count = 0; count < strlen(word); count++) {
            num += word[count]*(count+1);
        }
        return num;
}

struct occurance_t {
	int count;
	long hesh;
};

int main() {
	int counter = 0;
	struct occurance_t things[200] = {0};
	char word[200] = "\0";
	while(!(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l' && word[7] == '\0')) {
		scanf("%s%*c", word);
		int matched = 0;
		for(int i = 0; i < counter; i++) {
			if(things[i].hesh == hash(word)) {
				things[i].count++;
				matched = 1;
				break;
			}
		}
		if(!matched) {
			things[counter].hesh = hash(word);
			things[counter].count = 0; 
			counter++;
		}
	}
	for(int i = 0; i < counter; i++) {
		for(int j = 0; j < counter; j++)
			if(things[i].count > things[j].count) {
				struct occurance_t temp = things[i];
				things[i] = things[j];
				things[j] = temp;
			}
	} 

	printf("%d %ld",things[0].count+1 ,things[0].hesh);


	return 0;
}