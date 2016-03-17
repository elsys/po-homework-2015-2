#include <stdio.h>
#include <string.h>

char *find(char *, char);

int main(){

	char arr[400];
	char elem;
	int i;
	for(i = 0; i < 400; i++) {
		arr[i] = getchar();
		if(arr[i] == '\n') 
		{
			i--;
			break;
		}
	}

	scanf("%c", &elem);
	
	if(find(arr, elem) != NULL){
		printf("%c", *find(arr, elem));
	}
	else{
		printf("-1");
	}

	return 0;
}

char *find(char *haystack, char needle){

	char *pointer, position;
	int i;

	for(i = 0; i < strlen(haystack) - 1; i++){
		if(needle == haystack[i]){
			position = i + '0';
			break;
		}
	}
	
	if(position == 0)
		return NULL;

	else{
		pointer = &position;
		return pointer;
	}
}