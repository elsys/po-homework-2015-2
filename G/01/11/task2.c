#include <stdio.h>
#include <string.h>

long hash(char *word);

typedef struct{

	int count;
	long hesh;
	
}occurance_t;

int main() {

	int counter = 0, matched, i, j;
	
	occurance_t things[200];
	
	char word[200] = "\0";
	
	while(!(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l' && word[7] == '\0')) {
	
		scanf("%s%*c", word);
		matched = 0;
		for(i = 0; i < counter; i++) {
		
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
	for(i = 0; i < counter; i++) {
	
		for(j = 0; j < counter; j++)
		
			if(things[i].count > things[j].count) {
			
				occurance_t temp = things[i];
				things[i] = things[j];
				things[j] = temp;
				
			}
			
	} 

	printf("%d %ld\n",things[0].count+1 ,things[0].hesh);


	return 0;
}


long hash(char *word){

	long result = 42 ;
	int i;
	
	for(i = 0; i < strlen(word);i++){
	
		result += word[i] * (i+1);
		
	}	
	return result ;
}
