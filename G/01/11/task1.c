#include <stdio.h>
#include <string.h>

long hash(char *word);

int main(){
	char word[200];
	scanf("%s",word);
	printf("%ld\n",hash (word));
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
