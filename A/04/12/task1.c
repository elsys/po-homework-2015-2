#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void remove_all_chars(char* str, char c);
int checkSum(char* str);

int main()
{

    char s1[4][10]={"-933346-","-55583-","-4210-","-01-"};
    char s2[4][40]={"Bluebridge","Alyson Books","FUNimation Productions, Ltd.","Pyramid Books"};
    char str[20];
    char str2[20];

    int res, i1;
    char *house;
    scanf("%s",str);
    strcpy(str2,str);

    house=strstr(str2,s1[1]);

    remove_all_chars(str, '-');
    res=checkSum(str);

    printf("%d\n", res);
    if(res==1)
    {
        for(i1=0;i1<=3 ;i1++)
        {
            house=strstr(str2,s1[i1]);
            if(house!=NULL)
            {
                printf("%s",s2[i1]);
                return 0;
            }
        }
    }
    return 0;
}

void remove_all_chars(char* str, char c)
{
    char *pr=str, *pw=str;
    while(*pr)
    {
        *pw=*pr++;
        pw=pw+(*pw!=c);
    }
    *pw='\0';
}

int checkSum(char* str)
{
    int i, flag=0, chk=0;
    char str1[3];
    int coefs[]={1,3,1,3,1,3,1,3,1,3,1,3};

    i=strlen(str);
    if(i!=13)
    {
        return 0;
    }

    for(i=0; i<13; i++)
    {
        chk=isdigit(str[i]);
        if(chk==0)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    chk=0;
    for(i=0; i<12; i++)
    {
        chk=chk+(str[i]-48)*coefs[i];
    }
    i=10-(chk%10);
    if(i==(str[12]-48))
    {
        strncpy(str1,str,3);
        if((atoi(str1)==978) || (atoi(str1)==979))
        {
            return 1;
        }
        else
        {
            return 0;
        }
  }
  return 0;
}


