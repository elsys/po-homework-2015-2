#include <stdio.h>
#include <string.h>

typedef struct 
{
	int arg[2];
	int rez;
	char comand;
	char eror;
}comand_t;

comand_t get_stuff(char  aa[200]);

int main(int argc, char const *argv[])
{
	char b[200]={0};
	fgets(b,200, stdin);
	//puts(b);
	comand_t cc = get_stuff(b);


	switch(cc.comand)
			{
				case '+': 	cc.rez=cc.arg[0]+cc.arg[1];	break;
				case '-': 	cc.rez=cc.arg[0]-cc.arg[1];	break;
				case '/': (cc.arg[1]!=0) ? 	cc.rez=cc.arg[0]/cc.arg[1]	:  puts("invalid arithmetic operation"); break;
				case '*': 	cc.rez=cc.arg[0]*cc.arg[1];	break;
				case '%':  	cc.rez=cc.arg[0]%cc.arg[1];	break;
				case 16: 	cc.rez=cc.arg[1]+1;	break;

			}


			switch(cc.eror)
			{
				case 55 : puts("invalid command arguments"); return 1; break;
				case 89 : puts("invalid input");return 1;break;
				case 32 : puts("invalid command arguments");return 1;break;
				case 65 :puts("invalid command arguments");return 1;break;
				
			}


			if(cc.rez == 42)
			{
				puts("the answer to life, the universe and everything else");
				return 0;
			}


			printf("%d\n",cc.rez );
	return 0;
}



comand_t get_stuff(char aa[200])
{
	comand_t b;
	memset(&b,0 , sizeof(comand_t));	
	//puts(aa);

	int end1=-1;
	if(aa[0]=='+' || (aa[0]>='0' && aa[0]<='9') )
	{
		
		if(aa[0]=='+')
		{
			if(aa[1]=='+')
			{
				b.comand=16;

			}else b.eror = 55;
		}
		else	
			if(aa[0]>='0' && aa[0]<='9')
			{
				for (int i = 0; aa[i]>='0' && aa[i]<='9'; ++i)
				{
					b.arg[0]=b.arg[0]*10+aa[i]-'0';
					end1=i;
				}

			}

		if(aa[end1+1]!=' ' ) 
		{
		  	if(b.comand!=16)	b.eror=89;
			//puts("55");
		}
		else
		{
			switch(aa[end1+2])
			{
				case '+': b.comand='+' ;break;
				case '-': b.comand='-' ;break;
				case '/': b.comand='/' ;break;
				case '*': b.comand='*' ;break;
				case '%': b.comand='%'; break;

			}
		}		
		if(!(aa[end1+3]==' ' &&  (aa[end1+4]>='0' && aa[end1+4]<='9') ) )b.eror=32;
		else
			if((aa[end1+4]>='0' && aa[end1+4]<='9'))
			{
		//		puts("ssss");
				for (int i = end1+4; aa[i]>='0' && aa[i]<='9'; ++i)
					{
						b.arg[1]=b.arg[1]*10+aa[i]-'0';
						
					}

			}



	}
	else b.eror=65;
	//printf("%d\n",b.arg[0] );
	//printf("%d\n",b.arg[1] );
return b;
}