#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main(){
	char input[401]={'\0'}, symbol, *result;
	
	fgets(input, 401, stdin);
	symbol=getchar();
	
	result=find(input, symbol);
	
	if(result!=NULL){
		printf("%ld", result - input);
	}
	else{
		printf("-1");
	}
	
	return 0;
	
}

char* find(char *haystack, char needle){
	int i;
	char *result=NULL;
	for(i=0; i<400 && haystack[i]!='\0'; i++){
		if(haystack[i]==needle){
			result=&haystack[i];
			break;
		}
	}
	return result;
}
