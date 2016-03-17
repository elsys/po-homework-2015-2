#include <stdio.h>
#include <string.h>
#define MAX_SIZE 400 

char* find(char *, char);

int main(){

	char haystack[MAX_SIZE];
	char needle;
	
	fgets(haystack, MAX_SIZE, stdin);
	
	scanf("%c", &needle);
	
	printf("%d\n", (find(haystack, needle) != NULL) ? (find(haystack, needle) - haystack) : (-1) );
		
	return 0;
}

char* find(char *haystack, char needle)
{
	int counter;
	
	for(counter = 0; counter < strlen(haystack); counter++)
	{
		if(needle == haystack[counter]){
		
			return &haystack[counter];
		
		}
			
	
	}
	
	return NULL;
	
}
