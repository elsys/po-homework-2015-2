#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle){
	int i;
	for (i = 0; i < strlen(haystack); ++i){
		if(haystack[i] == needle){
			return &haystack[i];
		}
	}
	return NULL;
}
int main(){
	char haystack[400];
	char needle;
	char *finded;
	int position;
	scanf("%[^\n]s",haystack);
	scanf(" %c", &needle);
	finded = find(haystack, needle);
	//position = finded == NULL ? -1 : (int)(finded - line);
	if(finded == NULL){
		printf("-1");
	}
	else{
		printf("%d", finded);
	}
	return 0;
}
