#include <stdio.h>
#include <string.h>
char* find(char *, char );
int main()
{
    int i,l,result=-1;
   char str [400],needle;
   scanf("%[^\n]s",str);
   scanf(" %c",&needle);
   l=strlen(str);
   for(i=0;i<l;i++){
        if(find(&str[i], needle)){
			result = i;
			break;
		}
	}
   printf("%d",result);


    return 0;
}
char* find(char *str, char needle){
    if(needle == *str)
        return &str;
    else return NULL;
}
