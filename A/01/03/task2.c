#include<stdio.h>
#include<string.h>

long hash(char *word)
{ long hesh=42;
int i,l,kod;
l=strlen(word);

for(i=0;i<l;i++)
{
kod = *(word+i);
hesh=hesh+kod*(i+1);
}

return hesh;
}

struct occurance_t
{long hesh;
int times;
};

int main()
{ int n=603010,f,i,j=0,index=0,flag=1,max_occ=0,m;
char c[n];
char *cc = NULL;
char *space = NULL;
char curword[201];
fgets(c,n,stdin);
char stwd[8]={"vsmisal"};
long hesh;
struct occurance_t st[201];

cc = c;
while(cc)
{
space=strchr(cc,' ');
if(space)
{
strncpy(curword,cc,space-cc);
*(curword + (space-cc)) = '\0';
cc=space+1;
}

else
{strcpy(curword,cc);
 cc = NULL;
}
f=strcmp(curword,stwd);
if(f==0)
 {cc=NULL;break;}


hesh=hash(curword);
for(i=0;i<j;i++)
{if(st[i].hesh==hesh)
 {st[i].times++;flag=0;}
}
if(flag==1)
 {
 st[j].hesh=hesh;

 st[j].times=1;j++;
 }
}
for(m=0;m<j;m++)
{if(max_occ<st[m].times)
{
max_occ=st[m].times;
index=m;
}
}

printf("%d %ld",max_occ, st[index].hesh);


return 0;
}
