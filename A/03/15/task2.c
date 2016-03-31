#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct command_t{
	int argument1;
	char operator[3];
	int argument2;
	int type; // type 0 - > operator argument 2 type 1 - > argument 1 operator argument 2
	int error;
	int result;
};

int isUnaryOperator(char *operator);
int isSupportedOperator(char *string);
void parse(char *input, struct command_t *command);
int strToInt(char *string);
int exec_cmd(struct command_t *command);

int main(){
	int i=0, l;
	char input[420];
	struct command_t command[204];
	while(fgets(input, 421, stdin)!=NULL){
		parse(input, &command[i]);
		exec_cmd(&command[i]);
		i++;
	}
	for(l=0; l<i; l++){
		if(command[l].error==-1){
			printf("operation not supported");
		}
		else if(command[l].error==-2){
			printf("invalid command argument count");
		}
		else if(command[l].error==-3){
			printf("invalid command arguments");
		}
		else if(command[l].error==-4){
			printf("invalid input");
		}
		else if(command[l].error==-5){
			printf("invalid arithmetic operation");
		}
		else if(command[l].error==-42){
			printf("the answer to life, the universe and everything else");
		}
		else{
			printf("%d", command[l].result);
		}
		if(l!=i-1){
			printf("\n");
		}
	}
	return 0;
}

int exec_cmd(struct command_t *command){
	int temp, mult=1;
	if(command->error!=0){
		return command->error;
	}
	
	if(command->type==0){
		if(strcmp(command->operator, "++")==0){
			command->result=command->argument2+1;
		}
		else if(strcmp(command->operator, "!")){
			command->result=0;
			temp=command->argument2;
			if(temp%10 != 0){
				command->result+=1 * mult;
			}
			mult*=10;
		}
	}
	else{
		if(strcmp(command->operator, "+")==0){
			command->result = command->argument1 + command->argument2;
		}
		else if(strcmp(command->operator, "-")==0){
			command->result = command->argument1 - command->argument2;
		}
		else if(strcmp(command->operator, "/")==0){
			if(command->argument2 != 0){
				command->result = command->argument1 / command->argument2;
			}
			else{
				command->error=-5;
				return -5;
			}
		}
		else if(strcmp(command->operator, "*")==0){
			command->result = command->argument1 * command->argument2;
		}
		else if(strcmp(command->operator, "%")==0){
			command->result = command->argument1 % command->argument2;
		}
	}
	if(command->result == 42){
		command->error=-42;
		return -42;
	}
	return 0;
}

int isSupportedOperator(char *string){
	char operators[7][3]= {"+", "++", "-", "*", "/", "%", "!"};
	int i, supported=0;
	for(i=0; i<7; i++){
		if(strcmp(operators[i], string)==0){
			supported = 1;
			break;
		}
	}
	return supported;
}

void parse(char *input, struct command_t *command){
	int unary;
	char token[3][20]={{0}};
	sscanf(input, "%s %s %s", token[0], token[1], token[2]);
	if(strlen(token[2])<=0 && strlen(token[0])>0 && strlen(token[1])>0){
		unary=1;
	}
	else if(strlen(token[2])>0 && strlen(token[0])>0 && strlen(token[1])>0){
		unary=0;
	}
	else{
		unary=-1;
	}
	if(unary==1){
		
		command->type=0;
		if(isSupportedOperator(token[0])==0 && strToInt(token[1])==-1){
			command->error=-4;
		}
		else if(strToInt(token[1])==-1){
			command->error=-3;
		}
		else if(isUnaryOperator(token[0])==0){
			command->error=-2;
		}
		else if(isSupportedOperator(token[0])){
			strcpy(command->operator, token[0]);
			command->argument2=strToInt(token[1]);
			command->error=0;
		}
		
		else{
			command->error=-1;
		}
	}
	else if(unary==0){
		
		command->type=1;
		
		if(strToInt(token[0])==-1 && strToInt(token[2])==-1 && isSupportedOperator(token[1]) == 0){
			command->error=-4;
		}
		else if(strToInt(token[0])==-1 || strToInt(token[2])==-1){
			command->error=-3;
		}
		else if(isUnaryOperator(token[1])){
			command->error=-2;
		}
		
		else if(isSupportedOperator(token[1]) && isUnaryOperator(token[1])==0){
			command->argument1=strToInt(token[0]); // strtoint returns -1 if not number
			strcpy(command->operator, token[1]);
			command->argument2=strToInt(token[2]);
			command->error=0;
		}
		
		else{
			command->error=-1;
		}
	}
	else{
		command->error=-4;
	}
}

int isUnaryOperator(char *operator){
	if(strcmp(operator, "++")==0 || strcmp(operator, "!")==0){
		return 1;
	}
	return 0;
}

int strToInt(char *string){
	int i, mult=1, result=0;
	for(i=strlen(string)-1; i>=0; i--){
		if(string[i]<'0' || string[i] > '9'){
			return -1;
		}
		result+=mult*(string[i]-'0');
		mult*=10;
	}
	return result;
}
