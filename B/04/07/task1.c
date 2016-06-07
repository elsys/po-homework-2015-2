#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int CheckISBN(char* digits){
    int i,koda[13], s=0, a=0;
    for(i=0; i<strlen(digits); i++) if(digits[i] != '-') {
        koda[a] = digits[i]-'0';
        if(a%2==1) s += koda[a]*3;
        else s+= koda[a];
        a++;
    }
    s = 10-(s-koda[12])%10;
    return s;
}
void CheckBrand(char* digits){
    int i=6;
    char a[10];
    for(;digits[i]!='-';i++) a[i-6] = digits[i];
    if(strcmp(a,"933346") == 0) printf("\nBluebridge");
    if(strcmp(a,"55583") == 0) printf("\nAlyson Books");
    if(strcmp(a,"4210") == 0) printf("\nFUNimation Productions, Ltd.");
    if(strcmp(a,"01") == 0) printf("\nPyramid Books");
}
int main(){
    int i,end=1,shit=0;
    char a[20];
    scanf("%s",a);
    if((a[16]-'0') != CheckISBN(a)) end =5;
    if(strncmp(a,"978-",4) != 0 && strncmp(a,"979-",4) != 0) end = 0;
    for(i=0;i<strlen(a);i++) if(a[i] != '-') shit++;
    if(shit != 13) end=0;
    printf("%d",end);
    if(end == 1) CheckBrand(a);
return 0;
}
