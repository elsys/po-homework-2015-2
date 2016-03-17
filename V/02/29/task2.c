#include <stdio.h>
#include <stdlib.h>

char* find(char *haystack, char needle){
	int i = 0;
	char* ptr;
	while(haystack[i] != '\0'){
		if (haystack[i] == needle){
			return ptr = haystack + i;
		}
		i += 1;
	}
	return ptr = NULL;
}

int main(){
	char* all_data = malloc(sizeof(char) * 400);
	scanf("%[^\n]s", all_data);
	char j = getchar();
	j = getchar();	

	char* result = find(all_data,j);	

	if (result != NULL){
		printf("%d", result - all_data);
	} else {
		printf("-1");
	}
	free(all_data);
	return 0;
}