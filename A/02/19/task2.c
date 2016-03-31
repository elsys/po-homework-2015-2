#include <stdio.h>
#include <string.h>

char* find(char*, char);

int main(){

	char haystack[400];
	char needle;
	
	fgets(haystack, 400, stdin);
	scanf("%c", &needle);
	
	if(find(haystack, needle) != NULL){
		printf("%c", *find(haystack, needle));
	}
	else{
		printf("-1");
	}
}

char* find(char *haystack, char needle){

	char *ptr;
	char position = 0;
	
	for(int i = 0; i < strlen(haystack) - 1; i++){
	
		if(haystack[i] == needle){
			position = i + '0';
			break;
		}
	}
	
	if(position == 0)
		return NULL;
	else{
		ptr = &position;
		return ptr;
	}
}
