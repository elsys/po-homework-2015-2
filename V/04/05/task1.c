#include <stdio.h>
#include <string.h>

int main()
{
    char s[20];
    int a = 1,i,n,sum = 0,b = 1,j = 0,c = 0;
    scanf("%s",s);
    if(s[0]!='9'||s[1]!='7'||(s[2]!='8'&&s[2]!='9'))
        a = 0;
    if(s[6]=='9'&&s[7]=='3'&&s[8]=='3'&&s[9]=='3'&&s[10]=='4'&&s[11]=='6')
        c = 1;
    if(s[6]=='5'&&s[7]=='5'&&s[8]=='5'&&s[9]=='8'&&s[10]=='3')
        c = 2;
    if(s[6]=='4'&&s[7]=='2'&&s[8]=='1'&&s[9]=='0')
        c = 3;
    if(s[6]=='0'&&s[7]=='1')
        c = 4;
    n = strlen(s);
    for(i = 0;i < n; i++)
    {if(s[i]>'9'&&s[i]<'0'&&s[i]!='-')
        a = 0;
     s[i]=s[i]-'0';
    }
    for(i = 0;i < n- 1; i++)
    {

        if(s[i]<=9&&s[i]>=0)
        {sum=sum+s[i]*b;
            j++;
            if(j%2!=0)
                b = 3;
            else
                b = 1;
        }
    }
    if(s[n-1]!=10-(sum%10))
        a = 0;
    if(a)
    {
        printf("1");
        if(c==1)
            printf("\n Bluebridge");
        if(c==2)
            printf("\n Alyson Books");
        if(c==3)
            printf("\n FUNimation Productions, Ltd.");
        if(c==4)
            printf("\n Pyramid Books");
    }
    else
        printf("0");
    return 0;
}
