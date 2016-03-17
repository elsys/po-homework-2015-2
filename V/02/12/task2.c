#include <stdio.h>
#include <string.h>


char * find(char *haystack, char needle);

int main(){
	char needle;
	char haystack[400];
	fgets(haystack,400,stdin);
	scanf("%c",&needle);
	printf("%ld", find(haystack,needle) - haystack);
	return 0;
}

char *find(char *haystack, char needle){
	for(unsigned int i = 0; i < strlen(haystack);i++){
		if(needle == haystack[i]){
			return (haystack + i);
		}
	}
	return NULL;
}