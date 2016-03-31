#include <stdio.h>

char* find(char *haystack,char neelde);

int main()
{
    char izr[400];
    char buk;
    scanf("%[^\n]s",izr);
    scanf("%c",&buk);
    scanf("%c",&buk);
    if(find(izr,buk)==NULL)
        printf("NULL");
    else
    printf("%d",find(izr,buk)-izr);

    return 0;
}


char* find(char *haystack,char neelde){
    int i,l;
    int temp=0;

    for(l=0;haystack[l] != '\0';l++);

    for(i=0;i < l && temp != 1;i++){
        if(neelde==haystack[i])
            temp++;
    }
    if(temp==0)
        return NULL;
    else
        return &haystack[i];
}
