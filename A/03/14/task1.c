#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[12];
    char string[12];
    int i=0, x=0, y=0, z=0, k=0, sum=0, del=0, Error=0;

    scanf("%s",string);
    x=strlen(string);
    if(x>11)
    {
        Error++;
    }

    while(i<x)
    {
        arr[i]=string[i]-'0';
        i++;
    }
    i=0;


    if(arr[0]==0 && arr[1]==0)
    {
       x=(arr[2]*10)+arr[3];

       if((x>=1 && x<=12)||(x>=41 && x<=52))
       {
           i=0;
       }

       else
       {
           Error++;
       }
    }

    if(arr[0]!=0 && arr[1]!=0)
    {
       x=(arr[2]*10)+arr[3];

       if((x>=1 && x<=12)||(x>=21 && x<=32)||(x>=41 && x<=52))
       {
           i=0;
       }

        else
       {
           Error++;
       }
    }

    y=(arr[4]*10)+arr[5];

    if(x==1 || x==3|| x==5 || x==7 || x==8 || x==10 || x==12 || x==21 || x==23|| x==25 || x==27 || x==28 || x==30 || x==32 || x==41 || x==43|| x==45 || x==47 || x==48 || x==50 || x==52)
    {
        if(y>31)
        {
            Error++;
        }
    }

    if(x==4 || x==6 || x==9 || x==11 || x==24 || x==26 || x==29 || x==31 || x==44 || x==46 || x==49 || x==51)
    {
        if(y>30)
        {
            Error++;
        }
    }

    z=(arr[0]*10)+arr[1];
    k=z%4;

    if(k==0)
    {
        if(x==2 || x==22 || x==42)
        {
            if(y>29)
            {
                Error++;
            }
        }
    }

    if(k!=0)
    {
        if(x==2 || x==22 || x==42)
        {
            if(y>28)
            {
                Error++;
            }
        }
    }

    if(z==0 && x>=1 && x<=12)
    {
        if(x==2 || x==22 || 42)
        {
            if(y>28)
            {
                Error++;
            }
        }

    }

    sum=(arr[0]*2)+(arr[1]*4)+(arr[2]*8)+(arr[3]*5)+(arr[4]*10)+(arr[5]*9)+(arr[6]*7)+(arr[7]*3)+(arr[8]*6);
    del=sum%11;

    if(del==10)
    {
        del=0;
    }

    if(arr[9]!=del)
    {
        Error++;
    }

    if(Error==0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }


    return 0;
}
