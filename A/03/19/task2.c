#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define UNSUPPORTED_OPERATION_1 1
#define UNSUPPORTED_OPERATION_2 2
#define UNSUPPORTED_OPERATION_3 3
#define UNSUPPORTED_OPERATION_4 4
#define UNSUPPORTED_OPERATION_5 5
#define UNSUPPORTED_OPERATION_42 42

struct command_t{
	char expression[MAX];
	int answer;
	int wrong_op;
};

int exec_cmd(struct command_t *cmd);
int exceptions_cmd(struct command_t *cmd);
void exception_message(int);
int factorial(int);
int operation(int, int, char);
int num_shift(char*, int, int);
int unary_ex(char*, char*);

int main(){
	struct command_t cmd;	
	char input[MAX];
	
	scanf("%[^EOF]s", input);

	int j;
	do
	{	
		int l = strlen(input);

		for(j = 0; input[j] != '\n'; j++){
			cmd.expression[j] = input[j];
		}
		cmd.expression[j] = '\n';
		cmd.expression[j + 1] = '\0';


		if(exceptions_cmd(&cmd) == 0){
			cmd.answer = exec_cmd(&cmd);
		
			if(cmd.answer == 42)
				exception_message(42);
			else
				printf("%d\n", cmd.answer);
		}
		else{
			exception_message(exceptions_cmd(&cmd));
			printf("\n");
		}

					
		j++;
		if(input[j] == '\0') break;
		int k;
		int temp = j;
		for(k = 0; k < l - temp; k++){
			input[k] = input[j];
			j++;
		}
		input[k] = '\0';
		
	}
	while(1);	
	
	return 0;
}

int unary_ex(char* arr1, char* arr2){
	if(strcmp(arr1, "!") == 0){
		for(int i = 0; i < strlen(arr2); i++){
			if(arr2[i] < '0' || arr2[i] > '9')
				return UNSUPPORTED_OPERATION_4;
		return 0;
		}
	}
	
	if(strcmp(arr1, "++") == 0){
		for(int i = 0; i < strlen(arr2); i++){
			if(arr2[i] < '0' || arr2[i] > '9')
				return UNSUPPORTED_OPERATION_4;
		}
		return 0;
	}
	
	for(int i = 0; i < strlen(arr1); i++){
		if(arr1[i] < '0' || arr1[i] > '9')
			return UNSUPPORTED_OPERATION_4;
	}
	
	
	if(arr2[0] != '+' && arr2[0] != '-' && arr2[0] != '/' && arr2[0] != '*' && arr2[0] != '%')
		return UNSUPPORTED_OPERATION_4;
	else{
		/*if(strcmp(arr2, "++") == 0){
			return 0;*/
		if(strlen(arr2) == 1)
			return UNSUPPORTED_OPERATION_2;
		else
			return UNSUPPORTED_OPERATION_4;
	}
		return 0;
		
		return 0;

}

int exceptions_cmd(struct command_t *cmd){
	
	char arr1[MAX];
	char arr2[MAX];
	char arr3[MAX];

	int j;
	int i = 0;
	int fact = 0;
	for(j = 0; cmd->expression[i] != ' '; j++){
		arr1[j] = cmd->expression[i];
		i++;

		if(cmd->expression[i] == '\n') return UNSUPPORTED_OPERATION_2;
	}
	arr1[j] = '\0';
	
	i++;
	if(fact == 0){
		for(j = 0; cmd->expression[i] != ' '; j++){
			arr2[j] = cmd->expression[i];
			i++;
		
			if(cmd->expression[i] == '\n'){
				arr2[j + 1] = '\0';
				return unary_ex(arr1, arr2);
			}
		}
	}
	arr2[j] = '\0';
	if(strcmp(arr1, "!") == 0) return unary_ex(arr1, arr2);
	
	i++;
	for(j = 0; cmd->expression[i] != '\n'; j++){
		arr3[j] = cmd->expression[i];
		i++;
	}
	arr3[j] = '\0';
	

	int error = 0;
	
	for(i = 0; i < strlen(arr1); i++){
		if(arr1[i] < '0' || arr1[i] > '9'){
			error++;
			break;
		}
	}
	
	if(strcmp(arr3, "0") == 0 && strcmp(arr2, "/") == 0) return UNSUPPORTED_OPERATION_5;
	
	for(i = 0; i < strlen(arr3); i++){
		if(arr3[i] < '0' || arr3[i] > '9'){
			error++;
			break;
		}
	}
	
	for(i = 0; i < strlen(arr2); i++){
		if(arr2[i] != '+' && arr2[i] != '-' && arr2[i] != '/' && arr2[i] != '*' && arr2[i] != '%'){
			if(error > 0)
				return UNSUPPORTED_OPERATION_4;
			else if(error == 0)
				return UNSUPPORTED_OPERATION_1;
		}
		else if(error == 0 && strlen(arr2) == 1)
			return 0;
		else if(error == 2)
			return UNSUPPORTED_OPERATION_3;
		else if(strcmp(arr2, "++") == 0 && error == 0)
			return UNSUPPORTED_OPERATION_2;
		else
			return UNSUPPORTED_OPERATION_4;
	}
	return 0;
}

int exec_cmd(struct command_t *cmd){
	int i = 0;
	int num1;
	int num2;
	char op;
	
	int fact = 0;
	int start = 0;
	
	for(i = 0; cmd->expression[i] != ' '; i++){
			if(cmd->expression[i] == '!'){
				fact = 1;
				break;
			}
			if(cmd->expression[i] == '+'){
				num1 = num_shift(cmd->expression, start + 2, strlen(cmd->expression) - 1);
				return (num1 + 1);
			}
	}

	num1 = num_shift(cmd->expression, start, i);
	
	i++; 
	start = i;
	if(fact == 0){
	for(; cmd->expression[i] != ' '; i++){
		 	if(cmd->expression[i] == '+' && cmd->expression[i + 1] == '+'){
		 		num2 = 1;
		 		op = '+';

		 		return operation(num1, num2, op);
		 	}
		 	else if(cmd->expression[i + 1] == ' '){
		 		op = cmd->expression[i];
		 	}
		 }
	}
	
	if(fact == 1) {
		i++;
		start = 0;
	}
	num2 = num_shift(cmd->expression, start + 2, strlen(cmd->expression) - 1);
	
	if(fact == 1){
		return factorial(num2);
	}
	return operation(num1, num2, op);

	return 0;
}

int num_shift(char* input, int start_position, int end_position){
	char num[MAX];
	int cpy = start_position;
	
	for(int c = 0; c < end_position - cpy; c++){
		num[c] = input[start_position];
		start_position++;
	}
	num[end_position - cpy] = '\0';
	
	return atoi(num);
}

int operation(int num1, int num2, char op){
	switch(op){
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '/': return num1 / num2;
		case '*': return num1 * num2;
		case '%': return num1 % num2;
		}
	
	return 0;
}

int factorial(int n){	
	int fact = 1;
	  for (int c = 1; c <= n; c++){
    	fact = fact * c;
    }
    
    return fact;
}

void exception_message(int operation){
	switch(operation){
		case UNSUPPORTED_OPERATION_1:
			printf("operation not supported");
			break;
		case UNSUPPORTED_OPERATION_2:
			printf("invalid command argument count");
			break;
		case UNSUPPORTED_OPERATION_3:
			printf("invalid command arguments");
			break;
		case UNSUPPORTED_OPERATION_4:
			printf("invalid input");
			break;
		case UNSUPPORTED_OPERATION_5:
			printf("invalid arithmetic operation");
			break;
		case UNSUPPORTED_OPERATION_42:
			printf("the answer to life, the universe and everything else\n");
			break;
	}
}
