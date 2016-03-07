#include <stdio.h>
#include <string.h>
long hash(char * );
int main () {
	char word[200];
	fgets(word , 200 , stdin);
	hash (word);

 return 0;
}
long hash(char *word){
	
	int hesh = 42, helper = 0;
	int size = strlen (word);
	while(helper < size-1){
		
		hesh += word[helper] * (helper + 1);
		helper ++;
		
}

return printf("%d",hesh);

}




