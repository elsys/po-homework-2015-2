#include <stdio.h>
#include <string.h>
#include <ctype.h>

int leapYear(int year);
int chkEgn(char *);
char st1[12];
int coefs[]={2,4,8,5,10,9,7,3,6};
int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    scanf("%s",st1);
   	printf("%d",chkEgn(st1));
	return 0;
}

int leapYear(int year)
{
    if(year % 400==0)
    {
        return 1;
    }
    if(year % 100==0)
    {
        return 0;
    }
    if(year % 4==0)
    {
        return 1;
    }
    return 0;
}

int chkEgn(char *str)
{
    int dd, mm, yy, yyyy;
    int i, chk;
    int dayAdd;
    int flag=0;

    i=strlen(str);
    if(i!=10)
    {
        return 0;
    }

    for(i=0; i<10; i++)
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
    yy=(str[0]-48)*10+(str[1]-48);
    mm=(str[2]-48)*10+(str[3]-48);
    dd=(str[4]-48)*10+(str[5]-48);
    chk=(str[9]-48);
    if((mm>=1) && (mm<=12))
    {
        yyyy=1900+yy;
    }
    else if((mm>=21) && (mm<=32))
    {
        yyyy=2000+yy;
        mm-=20;
    }
    else if((mm>=41) && (mm<=52))
    {
        yyyy=1800+yy;
        mm-=40;
    }
    else
    {
        return 0;
    }

    dayAdd=leapYear(yyyy);
    days[1]=days[1]+dayAdd;
    if(!(dd>1 && dd<=days[mm-1]))
    {
        return 0;
    }

    int chkSum=0;
    for (i=0 ;i<9; i++)
    {
        chkSum=chkSum+(str[i]-48)*coefs[i];
    }
    chkSum=chkSum%11;
    if(chkSum==10)
    {
        chkSum=0;
    }

    if(chk==chkSum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
