#include <stdio.h>
#include <string.h>
#define HEYSTACK_SIZE 401
#define NOT_FOUND -1
char* find(char *, char);

int counter = 0;

int main () {

	char hayStack[401];
	char Needle;

	char *result = NULL;

	scanf("%[^\n]s",hayStack);
	getchar();
	
	Needle = getchar();

	if (find(hayStack, Needle) != NULL) {
		printf("%ld", find(hayStack, Needle) - hayStack);
	}
	else printf("%d",NOT_FOUND);

	return 0;
}

char* find (char *hay, char ndl) {

	for (; counter < strlen(hay); counter++) {
		if (hay[counter] == ndl) {
			return &hay[counter];
		}
	}
	return NULL;
}
