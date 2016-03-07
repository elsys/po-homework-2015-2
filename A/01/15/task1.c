#include <stdio.h>
#include <string.h>

long hash(char *word);

int main(){
	char input[200];
	
	scanf("%s", input);
	printf("%ld", hash(input));
	
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
