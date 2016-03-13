#include <stdio.h>
#include <string.h>
#define SIZE 200
#define MAX_WORDS 3000

typedef struct{

	long hash;
	int count;
	char word[4][200];

}occurance_t;

long hash(char *);
void sort(occurance_t *, int);

int main()
{

	int ctr = 0, print_ctr,check_ctr, new;
	char word[SIZE];
	occurance_t words[MAX_WORDS];
	    
	do{

		scanf("%s", word);

		if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l') {

			break;

		}
		
		new = 1;

		for(check_ctr = 0; check_ctr < ctr; check_ctr++){

			if(hash(word) == words[check_ctr].hash){

				strcpy(words[check_ctr].word[ words[check_ctr].count++], word);
				new = 0;
			
			}

		}
		
		if(new){
		
			words[ctr].hash = hash(word);
			words[ctr].count = 1;
			strcpy(words[ctr].word[0], word);
		
		}

	}while(ctr++ < MAX_WORDS);

	sort(words, ctr);

	for(check_ctr = 0; check_ctr < ctr; check_ctr++){
	
		if(words[check_ctr].count > 1){
		
			printf("%ld", words[check_ctr].hash);
		
			for(print_ctr = 0; print_ctr < words[check_ctr].count; print_ctr++){
			
				printf(" %s", words[check_ctr].word[print_ctr]);
			
			}
			
			printf("\n");
		
		}
	
	}

	return 0;

}

void sort(occurance_t *words, int size){

	int counter;
	occurance_t helper;
	
	for(counter = 0; counter < size; counter++){
	
		if(words[counter].hash > words[counter+1].hash){
		
			helper = words[counter];
			words[counter] = words[counter+1];
			words[counter+1] = helper;
		
		}
	
	}

}

long hash(char *word){

	int counter = 0;
	long hash_code = 42;
	
	while(counter++ < strlen(word)){
        
        	hash_code += word[counter - 1] * (counter);
        
    	}

	return hash_code;

}
