#include <stdio.h>

#define max 400

char* find(char *haystack, char needle);

int main()
{

    char haystack[max];
    char needle;
    int i=0;

    scanf("%[^\n]s",haystack);
    scanf(" %c",&needle);


char * ptr = find(haystack,needle);

printf("%d",(int)(ptr-haystack));

    return 0;

}

 char* find(char *haystack, char needle)
{
int i=0,help=0;

for(i=0;i<max;i++){

    if(haystack[i] == needle) { break;}
    
}

return (haystack + i);

}
