#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long hash(char *word){
	int i;
	long a=42;
	for(i=0;i<=strlen(word)-1;i++){
		a+=word[i]*(1+i);
	}
	return a;
}

int main(){
	char word[200];
	do{
		scanf("%s",word);
	}while(strlen(word)>200);
	printf("%ld",hash(word));
	return 0;
}
