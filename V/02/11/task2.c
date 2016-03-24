#include <stdio.h>
#include <string.h>

char* find(char *haystack,char needle){
	int i=0;
	int length=0;
	length=strlen(haystack);
	for (i=0;i<length;i++){
		if(needle==*(haystack+i)){
			return &haystack[i];
		}
	}
	return NULL;
}

int main()
{
	int i;
	char k;
	char symbol;
	char string[400];
	for(i=0;k!='\n';i++){
		string[i]=getchar();
		k=string[i];
	}
	scanf("%c",&symbol);
	if(find(string,symbol)){
		printf("%ld",((long)find(string,symbol)-string));
	}
	else{
		printf("-1");
	}
	return 0;
}
