#include <stdio.h>
#include <string.h>


long hash(char []);

int main(){
	char c_w;
	char word[200] = {0};
	for(int i = 0;i < 200;i++){
		scanf("%c",&c_w);
		// printf("Nigah %d\n",c_w );
		if(c_w == 10){
			// printf("Sup\n");
			break;

		}
		word[i] = c_w;		
	}
	printf("%ld",hash(word));
	return 0;
}

long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}