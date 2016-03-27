#include <stdio.h>
#include <string.h>

typedef struct{
	int argument1;
	int argument2;
	char operation;
	int result;
	int code;
	int type;
}command_t;

int exec_cmd(command_t*, char*, int);
int check_error1(char*);
int check_error2(char*);
int check_error3(char*);
int check_error4(char*, int*);
int check_error5(command_t*, int);
int check_valid_operators(char*, int);
int check_unary_operators(char*);
void arrange_command(command_t*, char*, int);
void find_result(command_t*, int);

int main()
{
	char input[100], c;
	int i = 0;
	command_t cmd[100];
	while(scanf("%[^\n]%c", input, &c) != EOF)
	{
	cmd[i].code = exec_cmd(cmd, input, i);
	if(cmd[i].code == 0) find_result(cmd, i);
	i++;
	}
	for(int j = 0; j < i; j++)
	{
		if(cmd[j].code == 0 && cmd[j].result != 42) printf("%d", cmd[j].result);
		else if(cmd[j].code == 0 && cmd[j].result == 42) printf("the answer to life, the universe and everything else");
		else if(cmd[j].code == -1) printf("operation not supported");
		else if(cmd[j].code == -2) printf("invalid command argument count");
		else if(cmd[j].code == -3) printf("invalid command arguments");
		else if(cmd[j].code == -4) printf("invalid input");
		else if(cmd[j].code == -5) printf("invalid arithmetic operation");
		if(j != i-1) printf("\n");
	}
	return 0;
}
int exec_cmd(command_t *cmd, char *input, int i)
{
	int error[5] = {0, 0, 0, 0, 0};
	int j, k = 0;
	error[0] = check_error1(input);
	error[1] = check_error2(input);
	error[2] = check_error3(input);
	if(error[0] && error[2])
	{
		if(input[0] == ' ') k++;
		for(j = k; input[j] != ' ' && j < strlen(input); j++);
		if(input[j] == ' ' && ((input[j+1] > '0' && input[j+1] < '9') || input[j+1] == '-' || (input[j+1] == '+' && input[j+2] != '+')))
			error[2] = 0;
	}
	if(!error[1] && error[2])
	{
		if(input[0] == ' ') k = 1;
		else k = 0;
		if(check_valid_operators(input, k-1) && !check_unary_operators(input))
		{
			error[1] = 1;
			error[2] = 0;
		}
	}	
	error[3] = check_error4(input, error);
	if(error[0] == 0 && error[1] == 0 && error[2] == 0)
	{ 
		arrange_command(cmd, input, i);
		error[4] = check_error5(cmd, i);
	}
	for(j = 4; j >= 0; j--)
	{
		if(error[j]) return (j+1)*(-1);
	}
	return 0;
}
int check_error1(char *input)
{
	int i = 0;
	if(input[0] == ' ') i++;
	if(check_valid_operators(input, i-1) && input[i+1] == ' ' && i+1 < strlen(input)) return 0;
	else if(input[i] == '+' && input[i+1] == '+' && input[i+2] == ' ' && i+2 < strlen(input)) return 0;
	else
	{
		while(input[i] != ' ' && i < strlen(input)) i++;
		if(input[i] == ' ')
		{
			if(check_valid_operators(input, i) && (input[i+2] == ' ' || i+2 == strlen(input)))
				return 0;
			else if(check_valid_operators(input, i) && input[i+2] == input[i+1] && input[i+3] == ' ')
				return 0;
			else return 1;
		}
	}
	return 1;
}
int check_valid_operators(char *input, int i)
{
	if(input[i+1] == '+') return 1;
	else if(input[i+1] == '-') return 1;
	else if(input[i+1] == '*') return 1;
	else if(input[i+1] == '/') return 1;
	else if(input[i+1] == '%') return 1;
	else if(input[i+1] == '!') return 1;
	else return 0;
}
int check_error2(char *input)
{
	int i = 0, k = 0;
	if(input[0] == ' ') i++;
	if(check_unary_operators(input))
	{
		while(input[i] != ' ') i++;
		for(i += 1; i < strlen(input); i++)
		{
			if(input[i] == ' ') k++;
		}
		if(k >= 1) return 1;
		else return 0;
	}
	while(input[i] != ' ' && i < strlen(input)) i++;
	if(( (input[i] != ' ' || input[i+2] != ' ') && check_valid_operators(input, i) ) || input[i+1] == '!') return 1;
	else return 0;
}
int check_unary_operators(char *input)
{
	int i = 0;
	if(input[0] == ' ') i++;
	if(input[i] == '!' && input[i+1] == ' ') return 1;
	else if(input[i] == '+' && input[i+1] == ' ') return 1;
	else if(input[i] == '-' && input[i+1] == ' ') return 1;
	else if(input[i] == '+' && input[i+1] == '+' && input[i+2] == ' ') return 1;
	return 0;
}
int check_error3(char *input)
{
	int i, k = 0;
	if(input[0] == ' ') k++;
	i = k;
	if(check_unary_operators(input))
	{
		while(input[i] != ' ') i++;
		for(i += 1; i < strlen(input); i++)
		{
			if( (input[i] < '0' || input[i] > '9') && !(input[i] == '-' || input[i] == '+') ) return 1;
		}
		return 0;
	}
	for(i = k; input[i] != ' ' && i < strlen(input); i++)
	{
		if( (input[i] < '0' || input[i] > '9') && !(input[i] == '-' || input[i] == '+') ) return 1;
	}
	do{
	i++;
	}while(input[i] != ' ' && i < strlen(input));
	for(i += 1; i < strlen(input); i++)
	{
		if( (input[i] < '0' || input[i] > '9') && !(input[i] == '-' || input[i] == '+') ) return 1;
	}
	return 0;
}
int check_error4(char *input, int *error)
{
	int count = 0;
	for(int i = 0; i < 5; i++)
	{
		if(error[i] == 1) count++;
	}
	if(count > 1) return 1;
	else return 0;
}
void arrange_command(command_t *cmd, char *input, int i)
{
	int j = 0, k = 0, negative = 0;
	if(input[0] == ' ') k++;
	if(check_unary_operators(input))
	{
		cmd[i].operation = input[k];
		if(input[k+1] == cmd[i].operation) cmd[i].operation = '*';
		while(input[k+j] != ' ') j++;
		cmd[i].argument2 = 0;
		cmd[i].type = 1;
		j++;
		if(input[k+j] == '+' || input[k+j] == '-') j++;
		if(input[k+j-1] == '-') negative = 1;
		for(; k+j < strlen(input); j++)
		{
			cmd[i].argument2 = cmd[i].argument2*10 + input[k+j]-'0';
		}
		if(negative == 1) cmd[i].argument2 *= -1;
	}
	else
	{
		cmd[i].argument1 = 0;
		cmd[i].type = 2;
		if(input[k+j] == '+' || input[k+j] == '-') j++;
		if(input[k+j-1] == '-') negative = 1;
		for(; input[k+j] != ' ' && k+j < strlen(input); j++)
		{
			cmd[i].argument1 = cmd[i].argument1*10 + input[k+j]-'0';
		}
		if(negative == 1) cmd[i].argument1 *= -1;
		negative = 0;
		j++;
		cmd[i].operation = input[k+j];
		cmd[i].argument2 = 0;
		j += 2;
		if(input[k+j] == '+' || input[k+j] == '-') j++;
		if(input[k+j-1] == '-') negative = 1;
		for(; k+j < strlen(input); j++)
		{
			cmd[i].argument2 = cmd[i].argument2*10 + input[k+j]-'0';
		}
		if(negative == 1) cmd[i].argument2 *= -1;
	}
}
int check_error5(command_t *cmd, int i)
{
	if( (cmd[i].operation == '/' || cmd[i].operation == '%') && cmd[i].argument2 == 0) return 1;
	else return 0;
}
void find_result(command_t *cmd, int i)
{
	if(cmd[i].type == 1)
	{
		if(cmd[i].operation == '!')
			cmd[i].result = !cmd[i].argument2;
		else if(cmd[i].operation == '*')
			cmd[i].result = cmd[i].argument2 + 1;
		else if(cmd[i].operation == '-')
			cmd[i].result = cmd[i].argument2*(-1);
		else if(cmd[i].operation == '+')
			cmd[i].result = cmd[i].argument2;
	}
	else if(cmd[i].type == 2)
	{
		if(cmd[i].operation == '+')
			cmd[i].result = cmd[i].argument1 + cmd[i].argument2;
		else if(cmd[i].operation == '-')
			cmd[i].result = cmd[i].argument1 - cmd[i].argument2;
		else if(cmd[i].operation == '*')
			cmd[i].result = cmd[i].argument1 * cmd[i].argument2;
		else if(cmd[i].operation == '/')
			cmd[i].result = cmd[i].argument1 / cmd[i].argument2;
		else if(cmd[i].operation == '%')
			cmd[i].result = cmd[i].argument1 % cmd[i].argument2;
	}
}
