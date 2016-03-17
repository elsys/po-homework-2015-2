#include <stdio.h>
#include <string.h>

void find(char *haystack, char needle){
    int count,lenght,counter = 1;
    lenght = strlen(haystack);
   for(count=0;count<lenght;count++ ){
	   if(haystack[count]==needle)break;
	   if(haystack[count]!=needle)counter++;
   }
   printf("\n%d",counter);
}

int main(){
	char haystack[400];
	 char needle;
	 scanf("%[^\n]s", haystack);
	 scanf("\n %c", &needle);
   find(haystack, needle);
}

