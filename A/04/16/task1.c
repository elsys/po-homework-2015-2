#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int counter = 0;
    int numcount = 0;
    int temp = 0;
    int flag = 0;
    int firstdashpos = 0;
    int checknumpos = 0;
    int checksum = 0;
    char isbn[20] = {0};
    scanf("%s", isbn);
    while(counter < 20 && numcount<13)
    {
        if(isbn[counter]>=48 && isbn[counter]<=57)
        {
            numcount++;
            checknumpos = counter;
        }
        else
        {
            if(isbn[counter]!='-')
            {
                printf("\n0");
                return 0;
            }
            if(isbn[counter+1]=='-')
            {
                printf("\n0");
                return 0;
            }
            if(flag==0)
            {
                firstdashpos = counter;
                if(isbn[counter+1]>=48 && isbn[counter+1]<=57)
                {
                    if(isbn[counter+2] == '-')
                    {
                        firstdashpos = counter+2;
                    }
                }
                flag = 1;
            }
        }
        counter++;
    }
    if(numcount!=13)
    {
        printf("\n0");
        return 0;
    }
    if(isbn[0]!='9')
    {
        printf("\n0");
        return 0;
    }
    if(isbn[1]!='7')
    {
        printf("\n0");
        return 0;
    }
    if(isbn[2]!='8')
    {
        if(isbn[2]!='9')
        {
            printf("\n0");
            return 0;
        }
    }
    counter = 0;
    numcount = 0;
    while(counter<20 && numcount<12)
    {
        if(isbn[counter]>=48 && isbn[counter]<=57)
        {
            numcount++;
            switch(numcount%2)
            {
                case 0:
                    temp = (isbn[counter]-48)*3;
                    break;
                default:
                    temp = (isbn[counter]-48);
                    break;
            }
            checksum = temp + checksum;
        }
        counter++;
    }
    checksum = checksum % 10;
    checksum = 10 - checksum;
    if(checksum!=(isbn[checknumpos]-48))
    {
        printf("\n0");
        return 0;
    }
    printf("\n1");
    if(isbn[6]=='9')
    {
        if(isbn[7]=='3')
        {
            if(isbn[8]=='3')
            {
                if(isbn[9]=='3')
                {
                    if(isbn[10]=='4')
                    {
                        if(isbn[11]=='6')
                        {
                            if(isbn[12]=='-')
                            {
                                printf("\nBluebridge");
                            }
                        }
                    }
                }
            }
        }
    }


    if(isbn[firstdashpos+1]=='5')
    {
        if(isbn[firstdashpos+2]=='5')
        {
            if(isbn[firstdashpos+3]=='5')
            {
                if(isbn[firstdashpos+4]=='8')
                {
                    if(isbn[firstdashpos+5]=='3')
                    {
                        if(isbn[firstdashpos+6]=='-')
                        {
                            printf("\nAlyson Books");
                        }
                    }
                }
            }
        }
    }

    if(isbn[firstdashpos+1]=='4')
    {
        if(isbn[firstdashpos+2]=='2')
        {
            if(isbn[firstdashpos+3]=='1')
            {
                if(isbn[firstdashpos+4]=='0')
                {
                    if(isbn[firstdashpos+5]=='-')
                    {
                        printf("\nFUNimation Productions, Ltd.");
                    }
                }
            }
        }
    }

    if(isbn[firstdashpos+1]=='0')
    {
        if(isbn[firstdashpos+2]=='1')
        {
                    if(isbn[firstdashpos+3]=='-')
                    {
                        printf("\nPyramid Books");
                    }
        }
    }
    return 0;
}
