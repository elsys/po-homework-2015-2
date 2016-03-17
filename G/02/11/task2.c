#include <stdio.h>
#include <stdlib.h>

char* find(char *haystack, const char needle){

	int i;

	for(i = 0; haystack[i] != '\0'; i++){
	
		if(haystack[i] == needle){
		
			return &haystack[i];
		
		}
			
	
	}
		
	return NULL;
}


int main (){

	char haystack[400];
	char needle;
	
	fgets(haystack, 400, stdin);
	
	scanf("%c", &needle);
	
	if(find(haystack, needle)){
	
		printf("%d", find(haystack, needle) - haystack);
	
	}else{
	
		printf("-1");
	
	}
	
	return 0;
}
