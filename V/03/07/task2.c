//Недовършено!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct command_t
{
	int res;
	char arg1[12], arg2[12], op[10];
};

int exec_cmd(struct command_t *cmd);
int is_num(char *s);
int operation(char *s);

short unsigned int command_is_not_in_the_middle=0;

int main()
{
	char input[100], a[15], b[15], c[15];
	int exec_code;
	short unsigned int i=0, j;
	struct command_t commands[1000];
	while(!feof(stdin))					//Последния ред се дублира.
	{
		fgets(input, sizeof(input), stdin);
		a[0]='\0';
		b[0]='\0';
		c[0]='\0';
		sscanf(input, "%s %s %s", a, b, c);
		if(is_num(a))
		{
			strcpy(commands[i].arg1, a);
			strcpy(commands[i].arg2, c);
			strcpy(commands[i].op, b);
		}
		else
		{
			strcpy(commands[i].arg1, b);
			strcpy(commands[i].arg2, c);
			strcpy(commands[i].op, a);
			command_is_not_in_the_middle=1;
		}
		exec_code=exec_cmd(&commands[i]);
		if(exec_code<0)
			commands[i].res=exec_code;
		if(commands[i].res==42)
			commands[i].res=-42;
		i++;
	}
	j=i;
	for(i=0; i<j; i++)
	{
		if(commands[i].res>=0)
			printf("%d",commands[i].res);
		else
			switch(commands[i].res)
			{
				case -1: printf("operation not supported"); break;
				case -2: printf("invalid command argument count"); break;
				case -3: printf("invalid command arguments"); break;
				case -4: printf("invalid input"); break;
				case -5: printf("invalid arithmetic operation"); break;
				case -42: printf("the answer to life, the universe and everything else"); break;
			}
		printf("\n");
	}
}

int exec_cmd(struct command_t *cmd)		//Връща грешни кодове!
{
	int arg1, arg2, op;
	unsigned short int arg1_is_num, arg2_is_num;
	arg1_is_num=is_num(cmd->arg1);
	arg2_is_num=is_num(cmd->arg2);
	op=operation(cmd->op);
	if(arg1_is_num==1 && arg2_is_num==1 && op==-1)
		return -1;
	if((op==-1 && (arg1_is_num!=1 || arg2_is_num!=1)) || (op!=2 && op!=7 && command_is_not_in_the_middle==1))
		return -4;
	if((op==2 && ((arg1_is_num==-1 && arg2_is_num==-1) || (arg1_is_num!=-1 && arg2_is_num!=-1))) || (op!=2 && op!=7 && (arg1_is_num==-1 || arg2_is_num==-1)))
		return -2;
	if(arg1_is_num==0 || arg2_is_num==0)
		return -3;
	arg1=strtol(cmd->arg1, NULL, 10);
	arg2=strtol(cmd->arg2, NULL, 10);
	if(op==5 && arg2==0)
		return -5;
	switch(op)
	{
		case 1: cmd->res=arg1+arg2; break;
		case 2:
			if(arg1_is_num==-1)
				cmd->res=arg2+1;
			else
				cmd->res=arg1+1;
			break;
		case 3: cmd->res=arg1-arg2; break;
		case 4: cmd->res=arg1*arg2; break;
		case 5: cmd->res=arg1/arg2; break;
		case 6: cmd->res=arg1%arg2; break;
		case 7: cmd->res=arg1+1; break;
	}
	return 0;
}

int is_num(char *s)
{
	int j, num=1, l;
	if(s[0]=='\0')
		return -1;
	l=strlen(s);
	for(j=0; j<l; j++)
		if((s[j]<'0' || s[j]>'9') && s[j]!='+' && s[j]!='-')
		{
			num=0;
			break;
		}
	return num;
}

int operation(char *s)
{
	if(strcmp(s, "+")==0)
		return 1;
	if(strcmp(s, "++")==0)
		return 2;
	if(strcmp(s, "-")==0)
		return 3;
	if(strcmp(s, "*")==0)
		return 4;
	if(strcmp(s, "/")==0)
		return 5;
	if(strcmp(s, "%")==0)
		return 6;
	if(strcmp(s, "!")==0)
		return 7;
	return -1;
}