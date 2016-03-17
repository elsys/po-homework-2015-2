#include <stdio.h>
#include <string.h>
#define MAX 400

char *find(char *haystack, char needle);

int main(){
	
	char haystack[400];
	char needle;
	int converter;
	
	fgets(haystack, 400, stdin);
	scanf("%c", &needle);

	find(haystack, needle);
	
	if(find(haystack, needle) != NULL){
		converter = find(haystack, needle) - haystack;
		printf("%d", converter);
	}
	else{
		printf("-1");
	}
	
	return 0;
}

char *find(char *haystack, char needle){
	
	char *null = NULL;
	
	for(int i = 0; i < strlen(haystack); i++){
		if(haystack[i] == needle){
			null = &haystack[i];
			break;
		}
	}
	return null;
}
