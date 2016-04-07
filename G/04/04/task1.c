#include<stdio.h>
#include<string.h>


int main ()
{
char isbn13[20]={0};
int arr[12];
int count=0;
int counter=0;
int lenght =0;
int sum1=0;
int sum2=0;
int sum3=0;
int suma=0;
int supp=0;

int help=0;
int helper=0;
int helpp=0;
scanf("%s",isbn13);
if((isbn13[0] == '9' && isbn13[1] == '7' && isbn13[2] == '8')||(isbn13[0] == '9' && isbn13[1] == '7' && isbn13[2] == '9'))
{
help=1;
}
else {help=0;}
lenght=strlen(isbn13);
for(counter=0;counter<lenght;counter++)
{
if(isbn13[counter]>=48 && isbn13[counter]<=57)
{count++;}
}
if(count==13){helper=1;}
else{helper = 0;}
count=0;
for(counter=0;counter<lenght;counter++)
{
if(isbn13[counter]!='-')
{
arr[count]=(isbn13[counter]-48);
count++;
}
}
for(counter=0;counter<=10;counter=counter+2)
{
sum1=sum1+arr[counter];
}
for(counter=1;counter<=11;counter=counter+2)
{
sum2=sum2+arr[counter];
}

sum3=sum2*3;
suma=sum1+sum3;

supp=suma%10;
if(arr[12]==10-supp){helpp=1;}
else {helpp=0;}
if(help==1 && helper==1 && helpp==1){printf("1\n");}
else {printf("0\n");}

if(isbn13[6]== '9' && isbn13[7]=='3' && isbn13[8]=='3' && isbn13[9]=='3' && isbn13[10] == '4' && isbn13[11] == '6')printf("Bluebridge\n");

if(isbn13[6]== '5' && isbn13[7]=='5' && isbn13[8]=='5' && isbn13[9]=='8' && isbn13[10] == '3' )printf("Alyson Books\n");

if(isbn13[6]== '4' && isbn13[7]=='2' && isbn13[8]=='1' && isbn13[9]=='0' )printf("FUNimation Productions, Ltd.\n");

if(isbn13[6]== '0' && isbn13[7]=='1')printf("Pyramid Books\n");


return 0 ;
}


