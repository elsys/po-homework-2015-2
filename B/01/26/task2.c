#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long hash(char *word);
struct occurance_t {
	long word_hash;
	int word_count;
};
int main(){
	struct occurance_t words[3001];
	char word[200];
	long int word_hash_c;
	int i,k,max = 0,which = 0;
	int y,m;
	for(m = 0;m < 3000;m++){
		words[ m ].word_count = 0;
		words[ m ].word_hash = 0;
	}	
	for( i = 0 ; i < 3001 ; i++){
		scanf("%s",word);
		word_hash_c = hash(word);
		for(k = 0; k < 3000 ; k++){
			words[ k ].word_hash = word_hash_c;
			words[ k ].word_count++;				
			break;					
			
		}	
		if(strcmp(word, "vsmisal") == 0)break;		
	}
	for(i = 0,k--; i < k ; i++ ){
		for(y = 1;y < k ;y++){
			if(words[ i ].word_hash != 0){
				if(words[ i ].word_hash == words[ y ].word_hash){
					words[ i ].word_count++;
					words[ y ].word_hash = 0;
					if(max < words[ i ].word_count){
						max = words[ i ].word_count;
						which = i;
					}
				}
			}
		}
	}
	printf("%d %ld",words[ which ].word_count,words[ which ].word_hash);
	
return 0;
}
long hash(char *word){
	long finaleye = 42;
	int count,i;
	count = strlen(word);
	for(i = 1; i <= count;i++){
		finaleye += (int)word[ i - 1 ] * i;
	}	
return finaleye;
}
