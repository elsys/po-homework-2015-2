#include <stdio.h>
#include <string.h>

int main(){
    char isbn[20] = {0};
    int i, j, a = 0, b = 0, c = 0, d = 0, sum = 0, s = 0, k = 0;
    scanf("%s", isbn);
    for(i = 0; i < strlen(isbn); i++){
        if(d == 2){
            for(s = i-1; isbn[s] != '-'; s++)
                k = k*10+(isbn[s]-48);
            d++;
        }
        if(isbn[i] == '-'){
            d++;
            for(j = i; j < strlen(isbn); j++)
                isbn[j] = isbn[j+1];
        }
    }
    if(strlen(isbn) != 13)
        a = 1;
    if(isbn[0] != '9' && isbn[1] != '7' && isbn[2] != '8' && isbn[2] != '9')
        b = 1;
    for(i = 0; i < strlen(isbn)-1; i += 2)
        sum += isbn[i] - 48;
    for(i = 1; i < strlen(isbn)-1; i += 2)
        sum = sum+3*(isbn[i]-48);
    if((10-sum%10) != isbn[12]-48)
        c = 1;
    if(a == 1 || b == 1 || c == 1)
        printf("0");
    else{
        printf("1");
        switch(k){
            case 933346: printf("\nBluebridge"); break;
            case 55583: printf("\nAlyson Books"); break;
            case 4210: printf("\nFUNimation Productions, Ltd."); break;
            case 01: printf("\nPyramid Books"); break;
        }
    }
    return 0;
}
