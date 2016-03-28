#include <stdio.h>

#define max 400

char* find(char *haystack, char needle);

int main()
{

    char haystack[max];

    char needle;

    scanf("%[^\n]s",haystack);
    scanf(" %c",&needle);


char * ptr = find(haystack,needle);

if(ptr == NULL)printf("-1");
else printf("%d",(int)(ptr-haystack));

    return 0;

}





 char* find(char *haystack, char needle)
{
int i=0;

char *helper= NULL;

for(i=0;i<max;i++){

    if(haystack[i] == needle) {helper = (haystack+i); break;}
}
return helper;
}
