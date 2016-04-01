#include <stdio.h>
#include <string.h>
#include <math.h>
struct command_t
{
	char op;
	int arg1;
	int arg2;
	double result;
};
int exec_cmd(struct command_t *cmd);
int adding_c(int a, int b, int c);
int check(char in[10000]);
int error = 0, count = 0;

int main()
{
	int a = 0, b = 0, c = 0;
	char op[2] = { 0 },in[10000] = { 0 };
	c = fgetc(stdin);
	if(c == ' ')
	{
		fgets(in,10000,stdin);
		error = check(in);
		count = sscanf(in," %s %d",op, &b);
		if(count != 2) error=4;
		if(strcmp(op,"++") == 0)
			{
				strcpy(op,"+");
				a = 1;
			}
		printf("%d %s %d\n",a, op, b);
	}
	else
	{
		fgets(in,10000,stdin);
		error = check(in);
		count = sscanf(in,"%d %s %d",&a, op, &b);
		if(count != 3) error=4;
		a = adding_c(a,b,(c-'0'));
		printf("%d %s %d\n",a, op, b);
	}

	struct command_t iny = { *(char *)op, a, b};
	exec_cmd(&iny);
	return 0;
}

int exec_cmd(struct command_t *cmd)
{
	if(strlen((char *)cmd->op) > 2) error = 1;
	else switch(cmd->op)
	{
		case '+': { cmd->result = cmd->arg1 + cmd->arg2; break; }
		case '-': { cmd->result = cmd->arg1 - cmd->arg2; break; }
		case '*': { cmd->result = cmd->arg1 * cmd->arg2; break; }
		case '/': { if(cmd->arg2 != 0) cmd->result = cmd->arg1 / cmd->arg2; else error = 5; break; }
		case '%': { cmd->result = cmd->arg1 % cmd->arg2; break; }
		case '!': { cmd->result = ! cmd->arg2; break;}
		default : { error = 1; break; }
	}
	if (cmd->result == 42) error = 42;
	switch(error)
	{
		case 0: { printf("%lf", cmd->result); break; }
		case 1: { printf("operation not supported"); break; }
		case 2: { printf("invalid command argument count"); break; }
		case 3: { printf("invalid command arguments"); break; }
		case 4: { printf("invalid input"); break; }
		case 5: { printf("invalid arithmetic operation"); break; }
		case 42: { printf("the answer to life, the universe and everything else"); break; }
	}
	return error;
}

int adding_c(int a, int b, int c)
{
	if(b>9) b /= 10;
	return a + c*pow(10, (int)log10((double)b)+1);
}

int check(char in[10000])
{
	for(int i = 0 ; in[i] != " " ; i++)
	{
		if(in[i] < 0 || in[i] > 9) return 3;
	}
	return 0;
}
