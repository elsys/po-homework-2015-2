#include<stdio.h>
#include<string.h>
int main()
{
    char c,s[20];
    int i,n,st=0,n1=0,n2=0;

    fgets(s,20,stdin);
    n=strlen(s)-1;

    for(i=0;i<n;i++)
       {
        if(s[i]<'0'||s[i]>'9')
          {

          if(s[i]!='+'&&s[i]!='-'&&s[i]!='!'&&s[i]!='%'&&s[i]!='/'&&s[i]!='*'&&s[i]!=' ')
                st=1;

            else
               {
                if(s[i+1]!=s[i] && s[i]!=' ')
                    c=s[i];
                else
                    if(s[i]!='+'&& s[i]!=' ')
                        st=5;
               }
          }
        }
    for(i=0;i<n;i++)
      {
          if(n1==0)
           {
                while(s[i]<='9'&&s[i]>='0')
                {
                    n1=n1*10+s[i]-'0';
                    i++;
                }
           }
           else
                while(s[i]<='9'&&s[i]>='0')
                {
                    n2=n2*10+s[i]-'0';
                    i++;
                }

            if(i!=0)
             if(s[i]=='+'&&s[i+1]=='+')
                st=2;

      }

        if(s[0]=='+'&&s[1]=='+')
            n1++;
        else
            if(c=='+')
                n1=n1+n2;
        if(c=='-')
            n1=n1-n2;
        if(c=='*')
            n1=n1*n2;
        if(c=='/')
            {if(n2==0)
                st=4;
                n1=n1/n2;
            }
        if(c=='%')
                n1=n1%n2;
        if(n1==42)
                st=3;


            if(st==0)
                printf("%d\n",n1);
            if(st==1)
                printf("invalid command arguments");
            if(st==2)
                printf("invalid input");
            if(st==3)
                printf("the answer to life, the universe and everything else");
            if(st==4)
                printf("invalid arithmetic operation");
            if(st==5)
                printf("invalid command argument count");






    return 0;
}
