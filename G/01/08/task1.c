#include <stdio.h>
#include <string.h>

long hashing(char [],int i);
int main()
{
int i=0;
long answ =0;
    char sent[200];
    scanf("%[^\n]s",sent);

i=strlen(sent);

   answ=hashing(sent,i);

    printf("%ld",answ);

    return 0;
}

long hashing(char str[],int len){

int i=0;
long eq=42;
for(i=0;i<len;i++){

    eq=eq+str[i]*(i+1);

    }
return eq;
}



