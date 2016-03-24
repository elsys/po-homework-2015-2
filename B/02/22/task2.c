#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main() {

	
	char text[500],symvol;
	fgets(text, 400 ,stdin);
	scanf("%c", &symvol);
	if(find(text, symvol)) {
	printf("%ld" , find(text, symvol) - text );

}else printf("-1");
	

		return 0 ;
}

char* find(char *haystack, char needle){
int i = 0;
	for (; i < strlen(haystack) ; i++){
		if(*(haystack + i) == needle){
			return &haystack[i+1]  ;
			break;
		}

	}
return 0;
}


