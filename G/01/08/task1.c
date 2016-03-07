#include <stdio.h>
#include <string.h>

int hashing(char [],int i);
int main()
{
int answ=0,i;
    char sent[200];
    scanf("%[^\n]s",sent);

i=strlen(sent);

   answ=hashing(sent,i);

    printf("%d",answ);

    return 0;
}

int hashing(char str[],int len){

int i,eq=42;

for(i=0;i<len;i++){

    eq=eq+str[i]*(i+1);

    }
return eq;
}

