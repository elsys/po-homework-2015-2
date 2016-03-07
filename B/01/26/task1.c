#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long hash(char *word);

int main(){
	char word[200];
	scanf("%s",word);
	printf("%ld\n",hash (word));
	return 0;
}	


long hash(char *word){
	long finaleye = 42 ;
	int count,i;
	count = strlen(word);
	for(i = 1; i <= count;i++){
		finaleye += (int)word[ i - 1 ] * i;
	}	
return finaleye ;
}

