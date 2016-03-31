#include <stdio.h>

#define max 400

char* find(char *hays, char n);

int main()
{

    char hays[max];

    char needle;

    scanf("%[^\n]s",hays);
    scanf(" %c",&n);


char * ptr = find(hays,n);

if(ptr == NULL)printf("-1");
else printf("%d",(int)(ptr-hays));

    return 0;

}





 char* find(char *hays, char n)
{
int i=0;

char *helper= NULL;

for(i=0;i<max;i++){

    if(hays[i] == needle) {helper = (hays+i); break;}
}
return helper;
}
