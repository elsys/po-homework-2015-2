#include <stdio.h>

int main()
{
     char s[11];
     int i,v,sum=0;
     scanf("%s",s);
     v=1;
     for(i=0;i<9;i++)
        if(s[i]<'0'||s[i]>'9')
        {v=0;
         break;
        }
     if(s[2]>'5')
        v=0;
     if(s[2]=='1'||s[2]=='3'||s[2]=='5')
        if(s[3]>'2')
            v=0;
     if(s[4]<'0'&&'3'>s[4])
        v=0;
     if(s[4]=='3')
        if(s[5]>'1')
            v=0;
    for(i=0;i<10;i++)
        s[i]=s[i]-48;
    sum=s[0]*2+s[1]*4+s[2]*8+s[3]*5+s[4]*10+s[5]*9+s[6]*7+s[7]*3+s[8]*6;
    sum=sum%11;
    if(sum==10)
        sum=0;
    if(sum!=s[9])
        v=0;
     printf("%d",v);


    return 0;
}
