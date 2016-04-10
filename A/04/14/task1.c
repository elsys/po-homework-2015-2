#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 21

int main()
{
    int i=0, len2=0, k=0, len=0, n=0, sum=0, BlBrdg=0, AlsnBks=0, FNmtnPrdctns=0, PrmdBks=0;
    char str[MAXLEN];
    int arr[MAXLEN]={0};
    scanf("%s",str);

        if(str[0]!='9'){
            i++;
        }

        if(str[1]!='7'){
            i++;
        }

        if(str[2]=='8' || str[2]=='9'){
            i=i;
        }
        else{
            i++;
        }

        if(str[3]!='-'){
            i++;
        }
        if(str[5]!='-'){
            i++;
        }

        if(str[4]=='0' || str[4]=='1'){
            i=i;
        }
        else{
            i++;
        }

        while(k<=strlen(str))
        {
            if(str[k]=='-'){
                len=len;
                k++;
            }
            else{
                len++;
                k++;
            }
        }
        len--;
        if(len!=13){
            i++;
        }

        if(str[6]=='9' && str[7]=='3' && str[8]=='3' && str[9]=='3' && str[10]=='4' && str[11]=='6')
        {
            BlBrdg++;
        }

        if(str[6]=='5' && str[7]=='5' && str[8]=='5' && str[9]=='8' && str[10]=='3')
        {
            AlsnBks++;
        }

        if(str[6]=='4' && str[7]=='2' && str[8]=='1' && str[9]=='0')
        {
            FNmtnPrdctns++;
        }

        if(str[6]=='0' && str[7]=='1')
        {
            PrmdBks++;
        }


        k=0;
        while(k<=strlen(str))
        {
            if(str[k]!='-')
            {
                arr[n]=str[k]-'0';
                n++;
                len2++;
            }
            k++;
        }

        sum=arr[0]+(3*arr[1])+arr[2]+(3*arr[3])+arr[4]+(3*arr[5])+arr[6]+(3*arr[7])+arr[8]+(3*arr[9])+arr[10]+(3*arr[11]);
        sum=sum%10;
        sum=10-sum;

        if(arr[12]!=sum){
            i++;
        }

        if(i==0){
            printf("1");
        }
        else{
            printf("0");
        }

        if(BlBrdg!=0){
            printf("\nBluebridge");
        }

        if(AlsnBks!=0){
            printf("\nAlyson Books");
        }

        if(FNmtnPrdctns!=0){
            printf("\nFUNimation Productions, Ltd.");
        }

        if(PrmdBks!=0){
            printf("\nPyramid Books");
        }

    return 0;
}
