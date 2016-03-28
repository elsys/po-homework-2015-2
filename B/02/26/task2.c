#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* find(char* haystack,char needle);

int main(){
	char haystack[400];
	char needle;
	fgets(haystack,400,stdin);
	scanf("%c",&needle);
	if(find(haystack,needle) == NULL )printf("-1");
	printf("%d",find(haystack,needle)-haystack);
	
return 0;
}

char* find(char* haystack,char needle){
	int i,h;
	h = strlen(haystack);
	for(i = 0;i < h;i++){
		if(haystack[ i ] == needle)return &haystack[ i ];					
	}
	return NULL;
}
