#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_valid(char* egn) {
	if(strlen(egn) != 10) 
		return 0;
	short mounth = ((egn[2] - 48)*10 + (egn[1] - 48)), day = ((egn[4] - 48)*10 + (egn[5] - 48));
	if(!((mounth > 0 && mounth < 12) || (mounth > 20 && mounth < 32) || (mounth > 40 && mounth < 52)))
		return 0;
	if(!(day > 0 || day <= 31))
		return 0;
	if((((((egn[0]-48)*2 + (egn[1]-48)*4 + (egn[2]-48)*8 + (egn[3]-48)*5 + (egn[4]-48)*10 + (egn[5]-48)*9 + (egn[6]-48)*7 + (egn[7]-48)*3 + (egn[8]-48)*6)%11) == 10) && (egn[9]-48) == 0))
		return 1;
	if((((egn[0]-48)*2 + (egn[1]-48)*4 + (egn[2]-48)*8 + (egn[3]-48)*5 + (egn[4]-48)*10 + (egn[5]-48)*9 + (egn[6]-48)*7 + (egn[7]-48)*3 + (egn[8]-48)*6)%11) == (egn[9] - 48)) 
		return 1;
	return 0;
}


int main() {
	int size = 0;
	char* egn = malloc(sizeof(char)), c;
	do {
		c = getchar();
		egn[size++] = c;
		egn = realloc(egn, size+1); 
	}while(c != ' ' && c != '\n' && c != EOF);

	egn[size-1] = '\0';

	printf("%d", is_valid(egn));

	free(egn);
	return 0;
}