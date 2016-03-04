#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void words(char *sent) {
	int l, count = 1;
	l = strlen(sent);
	for (; l > 0; l--) {
		if (sent[l] == ' ')
			count++;

	}
	printf("\nWords:%d", count);

}

void letters(char *sent) {
	int l = strlen(sent);
	int m=l;
	int count2 = 0;
	char count;
		for (count = 97; count <= 122; count++) { //vsqka bukvichka pootdelno ot ascii tablicaata
				for(l=m;l>=0;l--){
			     if (count == sent[l])
				count2++;}
			printf("\n %c = %d", count, count2);
			count2 = 0;
		}

	}



int main() {
	char sent[256];
	scanf("%[^\n]s", sent);
	letters(sent);
	words(sent);


	//printf("\n %s",sent);

	return 0;
}
