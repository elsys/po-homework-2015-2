#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void program_death()
{
    printf("0");
}
int main()
{
    int counter_n=0,counter_t=0,temp=0,checker=0,sum=0,k=1;
    char isbn[20];
    scanf("%s",isbn);
    while(temp<3)
    {
        if(temp==0)
        {
            if(isbn[temp]=='9')
            {
                checker++;
            }
        }
        if(temp==1)
        {
            if(isbn[temp]=='7')
            {
                checker++;
            }
        }
        if(temp==2)
        {
            if(isbn[temp]=='8' || isbn[temp]=='9')
            {
               checker++;
            }
        }
        temp++;
    }
    temp=0;
        while(temp<20)
        {
            if(isbn[temp]== '0')
                {
                    counter_n++;
                }
            if(isbn[temp]== '1')
                {
                    counter_n++;
                }
            if(isbn[temp]== '2')
                {
                    counter_n++;
                }
            if(isbn[temp]== '3')
                {
                    counter_n++;
                }
            if(isbn[temp]== '4')
                {
                    counter_n++;
                }
            if(isbn[temp]== '5')
                {
                    counter_n++;
                }
            if(isbn[temp]== '6')
                {
                    counter_n++;
                }
            if(isbn[temp]== '7')
                {
                    counter_n++;
                }
            if(isbn[temp]== '8')
                {
                    counter_n++;
                }
            if(isbn[temp]== '9')
                {
                    counter_n++;
                }
            temp++;
        }
        temp=1;
    if(checker!=3)
    {
        program_death();
    }
    else if(counter_n!=13)
    {
        program_death();
    }
    else{
    counter_n=0;
    for(counter_n=0;counter_n<=12;counter_n++)
            {
                if(isbn[counter_n]<=9 && isbn[counter_n]>=0)
                {
                    sum=sum+isbn[counter_n]*k;
                    counter_t++;
                    if(counter_t%2!=0)
                        k=3;
                    else
                        k=1;
                }
            }
        checker=0;
        if(isbn[counter_n]==10-(sum%10))
            {temp=0;}
        if(isbn[6]=='9'&& isbn[7]=='3' && isbn[8]=='3' && isbn[9]=='3' && isbn[10]=='4' && isbn[11]=='6')
            checker=1;
        if(isbn[6]=='5' && isbn[7]=='5' && isbn[8]=='5'&&isbn[9]=='8' && isbn[10]=='3')
            checker=2;
        if(isbn[6]=='4' && isbn[7]=='2' && isbn[8]=='1' && isbn[9]=='0')
            checker=3;
        if(isbn[6]=='0' && isbn[7]=='1')
            checker=4;
        if(temp==1)
                {
                    printf("1");
                    if(checker==1)
                        printf("\nBluebridge");
                    if(checker==2)
                        printf("\nAlyson Books");
                    if(checker==3)
                        printf("\nFUNimation Productions, Ltd.");
                    if(checker==4)
                        printf("\nPyramid Books");
                }
        else
                printf("0");
}
}
