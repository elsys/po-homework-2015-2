#include <stdio.h>
#include <string.h>
int main ()
{


  char array[100];
  char * pch;
scanf("%s",array);

int m=0;
int charcount = 0;
for(m=0; array[m]; m++) {
    if(array[m] != ' ') {
        charcount ++;
    }
}
charcount=charcount -4;
if(charcount != 13){
	printf("0\n");
	return 0;
}

  pch = strtok (array," ,.-");
const char *words[6] = { "978", "979", "933346", "55583","4210","01" }; 
   if (strcmp(pch,words[0]) == 0){
 printf ("1\n");

    pch = strtok (NULL, " ,.-");
pch = strtok (NULL, " ,.-");
	if (strcmp(pch,words[2]) == 0){
		printf("Bluebridge\n");
	}
	if (strcmp(pch,words[3]) == 0){
		printf("Alyson Books\n");
	}
	if (strcmp(pch,words[4]) == 0){
		printf("FUNimation Productions, Ltd.\n");
	}
	if (strcmp(pch,words[5]) == 0){
		printf("Pyramid Books\n");
	}

}else{
	printf("0\n");
}
		

  return 0;
}
