#include<stdio.h>
#include<string.h>
long hash(char *word)
{
long hash_of_word = 42;
int i;
int length = strlen(word);
i=0;
do
{
 
hash_of_word +=word[i]*(i+1);
++i;
 
}while(i < length);
 
return hash_of_word;
 
}
 
 
 
 
int main (){
   char word[200];
 
scanf("%s",&word);
printf("%ld",hash(word));
 
return 0;
}
