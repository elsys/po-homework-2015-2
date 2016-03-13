 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int long hash(char *word);
int main()
{
   char word[200];

  fgets(word,200,stdin);

hash(word);

   return 0;
}
int long hash(char *word)
{

   int i;
   int core =1 ;
   int go;
   int helper=0;
   int answer=0;
int home ;
   go = strlen(word);
home = go-1;
   for(i=0;i<home;i++)

   {
     helper = word[i] * core;
     answer = answer + helper;
     core ++;
   }
answer = answer + 42;
printf("%d",answer);
return 0;
} 
