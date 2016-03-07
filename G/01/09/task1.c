#include <stdio.h>
#include <string.h>

long hash(char *word){
	long res = 42;	
	int i=0;
	int multiplier = 1;
	char duma[200];
	int lenght = strlen(duma); 
	strcpy(duma, word);
	do{
		res = res+(duma[i]*multiplier);
		i++;
		multiplier++;
	}while(i<=lenght);
	
	return res;
}

int main(){

	char word[200];
	scanf("%s", &word);
	printf("%ld",hash(word));

return 0;
}
