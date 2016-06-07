#include <stdio.h>
#include <string.h>

int main()
{
    char s[20];
    int v=1,i,n,sum=0,k=1,j=0,c=0;
    scanf("%s",s);
    if(s[0]!='9'||s[1]!='7'||(s[2]!='8'&&s[2]!='9'))
        v=0;
    if(s[6]=='9'&&s[7]=='3'&&s[8]=='3'&&s[9]=='3'&&s[10]=='4'&&s[11]=='6')
        c=1;
    if(s[6]=='5'&&s[7]=='5'&&s[8]=='5'&&s[9]=='8'&&s[10]=='3')
        c=2;
    if(s[6]=='4'&&s[7]=='2'&&s[8]=='1'&&s[9]=='0')
        c=3;
    if(s[6]=='0'&&s[7]=='1')
        c=4;
    n=strlen(s);
    for(i=0;i<n;i++)
    {if(s[i]>'9'&&s[i]<'0'&&s[i]!='-')
        v=0;
     s[i]=s[i]-'0';
    }
    for(i=0;i<n-1;i++)
    {

        if(s[i]<=9&&s[i]>=0)
        {sum=sum+s[i]*k;
            j++;
            if(j%2!=0)
                k=3;
            else
                k=1;
        }
    }
    if(s[n-1]!=10-(sum%10))
        v=0;
    if(v)
    {
        printf("1");
        if(c==1)
            printf("\nBluebridge");
        if(c==2)
            printf("\nAlyson Books");
        if(c==3)
            printf("\nFUNimation Productions, Ltd.");
        if(c==4)
            printf("\nPyramid Books");
    }
    else
        printf("0");

    return 0;
}
