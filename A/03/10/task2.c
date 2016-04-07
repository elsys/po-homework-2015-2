#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct command_t
{
	int arg1;
	int arg2;
	int result;
	char operation[3];
	char symbol[10][20];
};

int command_executive(struct command_t *command);
void do_operation(struct command_t *command);
int error1_check(struct command_t  *command);
int error2_check(struct command_t *command);
int error3_check(struct command_t *command);
int error4_check(struct command_t *command);
int error5_check(struct command_t *command);
int number_check(char *symbol);
int operation_check(char *symbol);
int unary_operator_check(char *symbol);
int binary_check(char *symbol);

int main()
{
	char string[100];
	char	symbol[10][20]={"","","","","","","","","",""};
	char *temp;
	int j=0,string_check=0,code_error=0;;
	struct command_t command;
	while(scanf("%[^\n]\n",string)!=EOF)
	{
		for(j=0;j<10;j++)
		{
			strcpy(symbol[j],"");
		}
		for(j=0;j<10;j++)
		{
			strcpy(command.symbol[j],"");
		}
		temp=strtok(string," ");
		j=0;
		while(temp!=0 && j<10)
		{
			strcpy(symbol[j],temp);
			j++;
			temp=strtok(NULL," ");
		}
		for(j=0;strcmp(symbol[j],"")!=0;j++)
		{
			strcpy(command.symbol[j],symbol[j]);
		}
		if(string_check!=0)
			printf("\n");
		code_error=0;
		if((code_error=command_executive(&command))==0)
		{
			if(command.result!=42)
				printf("%d",command.result);
			else
				printf("the answer to life, the universe and everything else");
		}
		else{
			if(code_error==-1)
				printf("operation not supported");
			if(code_error==-2)
				printf("invalid command argument count");
			if(code_error==-3)
				printf("invalid command arguments");
			if(code_error==-4)
				printf("invalid input");
			if(code_error==-5)
				printf("invalid arithmetic operation");
		}
		string_check=1;
	}
	return 0;
}

int command_executive(struct command_t *command)
{
	if(error1_check(command))
		return -1;
	if(error2_check(command))
		return -2;
	if(error3_check(command))
		return -3;
	if(error4_check(command))
		return -4;
	if(error5_check(command))
		return -5;
	if(number_check(command->symbol[0]))
	{
		command->arg1=atoi(command->symbol[0]);
		strcpy(command->operation,command->symbol[1]);
		command->arg2=atoi(command->symbol[2]);
	}
	else
	{
		strcpy(command->operation,command->symbol[0]);
		command->arg1=atoi(command->symbol[1]);
	}
	do_operation(command);
	return 0;
}

int error1_check(struct command_t *command)
{
	if(number_check(command->symbol[0]))
        if(number_check(command->symbol[2]))
            if(!(operation_check(command->symbol[1])))
                if(strcmp(command->symbol[3],"")==0)
                    return 1;
	if(number_check(command->symbol[1]))
        if(!(operation_check(command->symbol[0])))
            if(strcmp(command->symbol[2],"")==0)
                return 1;
	return 0;
}

int error2_check(struct command_t *command)
{
    if(number_check(command->symbol[0]))
        if(unary_operator_check(command->symbol[1]))
            if(number_check(command->symbol[2]))
                if(strcmp(command->symbol[3],"")==0)
                    return 1;
    if(number_check(command->symbol[0]))
        if(binary_check(command->symbol[1]))
            if(strcmp(command->symbol[2],"")==0)
                return 1;
	return 0;
}

int error3_check(struct command_t *command)
{
	if((((!(number_check(command->symbol[0])) && strcmp(command->symbol[0],"")!=0) || (!(number_check(command->symbol[2])) && strcmp(command->symbol[2],"")!=0)) && operation_check(command->symbol[1]) && strcmp(command->symbol[3],"")==0) ||
		((!(number_check(command->symbol[1])) && strcmp(command->symbol[1],"") != 0) && operation_check(command->symbol[0]) && strcmp(command->symbol[2],"")==0))
		return 1;
	return 0;
}

int error4_check(struct command_t *command)
{
	if(!(number_check(command->symbol[0]) && operation_check(command->symbol[1]) && number_check(command->symbol[2]) && strcmp(command->symbol[3],"")==0) &&
		!(number_check(command->symbol[1]) && operation_check(command->symbol[0]) && strcmp(command->symbol[2],"")==0))
		return 1;
	return 0;
}

int error5_check(struct command_t *command)
{
	if(number_check(command->symbol[0]))
	{
        if((strcmp(command->symbol[1],"/")==0))
            if(number_check(command->symbol[2]))
                if(atoi(command->symbol[2])==0)
                    if(strcmp(command->symbol[3],"")==0)
        return 1;
        if((strcmp(command->symbol[1], "%")==0))
            if(number_check(command->symbol[2]))
                if(atoi(command->symbol[2])==0)
                    if(strcmp(command->symbol[3],"")==0)
        return 1;
    }
	return 0;
}

int number_check(char *symbol)
{
	int j=0;
	if(strcmp(symbol,"")==0)
        return 0;
	j=0;
	if(symbol[j]=='-')
	{
		if(strlen(symbol)>1)
            	j++;
        	else
            	return 0;
	}
	for(;j<strlen(symbol);j++)
		if(!isdigit(symbol[j]))
			return 0;
	return 1;
}

int operation_check(char *symbol)
{
	char operations[7][3]={"+", "++", "-", "*", "/", "%", "!"};
	int j=0;
	if(strcmp(symbol,"")==0)
        return 0;
	for(j=0;j<7;j++)
		if(strcmp(symbol, operations[j])==0)
			return 1;
	return 0;
}

int unary_operator_check(char *symbol)
{
	char operations[2][3]={"++", "!"};
	int j=0;
	if(strcmp(symbol,"")==0)
        return 0;
	for(j=0;j<2;j++)
		if(strcmp(symbol,operations[j])==0)
			return 1;
	return 0;
}

int binary_check(char *symbol)
{
	char operations[5][3]={"+", "-", "*", "%", "!"};
	int j=0;
	if(strcmp(symbol,"")==0)
        return 0;
	for(j=0;j<5;j++)
		if(strcmp(symbol,operations[j])==0)
			return 1;
	return 0;
}

void do_operation(struct command_t *command)
{
	if(strcmp(command->operation,"+")==0)
	{
		command->result=command->arg1+command->arg2;
	}
	else if(strcmp(command->operation,"++")==0)
	{
		command->result=command->arg1+1;
	}
	else if(strcmp(command->operation,"-")==0)
	{
		command->result=command->arg1-command->arg2;
	}
	else if(strcmp(command->operation,"*")==0)
	{
		command->result=command->arg1*command->arg2;
	}
	else if(strcmp(command->operation,"/")==0)
	{
		command->result=command->arg1/command->arg2;
	}
	else if(strcmp(command->operation,"%")==0)
	{
		command->result=command->arg1 % command->arg2;
	}
	else
	{
		command->result=(command->arg1==0)?1:0;
	}
}
