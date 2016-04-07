#include <stdio.h>
#include <stdlib.h>

int main()
{
    char isbn[18];
    int temp[14];
    int kushta=0;
    int i,l,j,a=0,b=0,c=0,d=0,sum=0,x=0;
    scanf("%s",isbn);
    l=strlen(isbn);
    for(i=0;i<l;i++){
        if(d==2){
            for(x=i-1;isbn[x] != '-';x++){
                kushta=kushta*10+(isbn[x]-48);
            }
            d++;
        }
        if(isbn[i] == '-'){
            d++;
            for(j=i;j<l;j++){
                isbn[j]=isbn[j+1];
            }
        }
    }
    l=l-4;
    if(l != 13)
        a=1;
    if(isbn[0] != '9')
        b=1;
    if(isbn[1] != '7')
        b=1;
    if(isbn[2] != '8' && isbn[2] != '9')
        b=1;
    for(i=0;i<l;i++){
        if(isbn[i] == '0')
            temp[i]=0;
        if(isbn[i] == '1')
            temp[i]=1;
        if(isbn[i] == '2')
            temp[i]=2;
        if(isbn[i] == '3')
            temp[i]=3;
        if(isbn[i] == '4')
            temp[i]=4;
        if(isbn[i] == '5')
            temp[i]=5;
        if(isbn[i] == '6')
            temp[i]=6;
        if(isbn[i] == '7')
            temp[i]=7;
        if(isbn[i] == '8')
            temp[i]=8;
        if(isbn[i] == '9')
            temp[i]=9;
    }
    for(i=0;i<l-1;i+=2)
        sum=sum+temp[i];
    for(i=1;i<l-1;i+=2)
        sum=sum+3*temp[i];
    if((10-sum%10) != temp[12])
        c=1;
    if(a==1 || b==1 || c==1)
        printf("0");
    else{
        printf("1");
        if(kushta==933346)
            printf("\nBluebridge");
        if(kushta==55583)
            printf("\nAlyson Books");
        if(kushta==4210)
            printf("\nFUNimation Productions, Ltd.");
        if(kushta==01)
            printf("\nPyramid Books");
    }

    return 0;
}
