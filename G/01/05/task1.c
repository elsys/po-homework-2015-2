#include <stdio.h>
#include <string.h>

long hash(char *word);

int main(){


char word[200];
printf("%ld",hash(word));
return 0;
}


long hash(char *word){
int counter,b,a=42;
scanf("%s",word);
b=strlen(word);
for(counter=1;word[counter-1]!='\0';counter++){

a=a+(word[counter-1]*counter);

}
return a;
}



