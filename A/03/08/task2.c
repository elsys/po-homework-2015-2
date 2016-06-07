#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct command_t{
	int arg1, arg2, result;
	char operation[3];
	char token[10][20];
};

int cmd_exec(struct command_t* command);
void DoOperation(struct command_t* command);
int error1(const struct command_t* command);
int error2(const struct command_t* command);
int error3(const struct command_t* command);
int error4(const struct command_t* command);
int error5(const struct command_t* command);
int isNum(const char* token);
int isOperation(const char* token);
int isUnary(const char* token);
int isBinary(const char* token);

int main(){
	char line[100], token[10][20] = {"","","","","","","","","",""};
	char* temp;
	int i = 0, newlineChecker = 0;

	while(scanf("%[^\n]\n", line) != EOF){

		struct command_t command;

        for(i = 0; i < 10; i++){
			strcpy(token[i], "");
		}
		for(i = 0; i < 10; i++){
			strcpy(command.token[i], "");
		}

		temp = strtok(line, " ");
		i = 0;
		while(temp != 0 && i < 10){
			strcpy(token[i], temp);
			i++;
			temp = strtok(NULL, " ");
		}

		i = 0;
		while(strcmp(token[i], "") != 0){
			strcpy(command.token[i], token[i]);
			i++;
		}

		if(newlineChecker != 0)
			printf("\n");
		int errCode = 0;
		if((errCode = cmd_exec(&command)) == 0){
			if(command.result != 42)
				printf("%d", command.result);
			else
				printf("the answer to life, the universe and everything else");

		}
		else{
			if(errCode == -1)
				printf("operation not supported");
			if(errCode == -2)
				printf("invalid command argument count");
			if(errCode == -3)
				printf("invalid command arguments");
			if(errCode == -4)
				printf("invalid input");
			if(errCode == -5)
				printf("invalid arithmetic operation");
		}
		newlineChecker = 1;
	}

	return 0;
}

int cmd_exec(struct command_t* command){
	if(error1(command))
		return -1;
	if(error2(command))
		return -2;
	if(error3(command))
		return -3;
	if(error4(command))
		return -4;
	if(error5(command))
		return -5;

	if(isNum(command->token[0])){
		command->arg1 = atoi(command->token[0]);
		strcpy(command->operation, command->token[1]);
		command->arg2 = atoi(command->token[2]);
	}
	else{
		strcpy(command->operation, command->token[0]);
		command->arg1 = atoi(command->token[1]);
	}

	DoOperation(command);
	return 0;
}

int error1(const struct command_t* command){
    /*if((isNum(command->token[0]) && isNum(command->token[2]) && !(isOperation(command->token[1])) && strcmp(command->token[3], "") == 0) ||
		(isNum(command->token[1]) && !(isOperation(command->token[0])) && strcmp(command->token[2], "") == 0))*/
	if(isNum(command->token[0]))
        if(isNum(command->token[2]))
            if(!(isOperation(command->token[1])))
                if(strcmp(command->token[3], "") == 0)
                    return 1;
	if(isNum(command->token[1]))
        if(!(isOperation(command->token[0])))
            if(strcmp(command->token[2], "") == 0)
                return 1;
	return 0;
}

int error2(const struct command_t* command){
	/*if((isNum(command->token[0]) && isUnary(command->token[1]) && isNum(command->token[2]) && strcmp(command->token[3], "") == 0) ||
		(isNum(command->token[0]) && isBinary(command->token[1]) && strcmp(command->token[2], "") == 0))*/
    if(isNum(command->token[0]))
        if(isUnary(command->token[1]))
            if(isNum(command->token[2]))
                if(strcmp(command->token[3], "") == 0)
                    return 1;
    if(isNum(command->token[0]))
        if(isBinary(command->token[1]))
            if(strcmp(command->token[2], "") == 0)
                return 1;
	return 0;
}

int error3(const struct command_t* command){
	if((((!(isNum(command->token[0])) && strcmp(command->token[0], "") != 0) || (!(isNum(command->token[2])) && strcmp(command->token[2], "") != 0)) && isOperation(command->token[1]) && strcmp(command->token[3], "") == 0) ||
		((!(isNum(command->token[1])) && strcmp(command->token[1], "") != 0) && isOperation(command->token[0]) && strcmp(command->token[2], "") == 0))
		return 1;
	return 0;
}

int error4(const struct command_t* command){
	if(!(isNum(command->token[0]) && isOperation(command->token[1]) && isNum(command->token[2]) && strcmp(command->token[3], "") == 0) &&
		!(isNum(command->token[1]) && isOperation(command->token[0]) && strcmp(command->token[2], "") == 0))
		return 1;
	return 0;
}

int error5(const struct command_t* command){
	//if(isNum(command->token[0]) && ((strcmp(command->token[1], "/") == 0) || strcmp(command->token[1], "%")) && (isNum(command->token[2]) && atoi(command->token[2]) == 0) && strcmp(command->token[3], "") == 0)
	if(isNum(command->token[0])){
        if((strcmp(command->token[1], "/") == 0))
            if(isNum(command->token[2]))
                if(atoi(command->token[2]) == 0)
                    if(strcmp(command->token[3], "") == 0)
        return 1;
        if((strcmp(command->token[1], "%") == 0))
            if(isNum(command->token[2]))
                if(atoi(command->token[2]) == 0)
                    if(strcmp(command->token[3], "") == 0)
        return 1;
    }
	return 0;
}

int isNum(const char* token){
	if(strcmp(token, "") == 0)
        return 0;

	int i = 0;
	if(token[i] == '-'){
		if(strlen(token) > 1)
            i++;
        else
            return 0;
		}
	for(; i < strlen(token); i++)
		if(!isdigit(token[i]))
			return 0;
	return 1;
}

int isOperation(const char* token){
    if(strcmp(token, "") == 0)
        return 0;

	char operations[7][3] = {"+", "++", "-", "*", "/", "%", "!"};
	int i;

	for(i = 0; i < 7; i++)
		if(strcmp(token, operations[i]) == 0)
			return 1;
	return 0;
}

int isUnary(const char* token){
    if(strcmp(token, "") == 0)
        return 0;

	char operations[2][3] = {"++", "!"};
	int i;

	for(i = 0; i < 2; i++)
		if(strcmp(token, operations[i]) == 0)
			return 1;
	return 0;
}

int isBinary(const char* token){
    if(strcmp(token, "") == 0)
        return 0;

	char operations[5][3] = {"+", "-", "*", "%", "!"};
	int i;

	for(i = 0; i < 5; i++)
		if(strcmp(token, operations[i]) == 0)
			return 1;
	return 0;
}

void DoOperation(struct command_t* command){
	if(strcmp(command->operation, "+") == 0){
		command->result = command->arg1 + command->arg2;
	}else if(strcmp(command->operation, "++") == 0){
		command->result = command->arg1 + 1;
	}else if(strcmp(command->operation, "-") == 0){
		command->result = command->arg1 - command->arg2;
	}
	else if(strcmp(command->operation, "*") == 0){
		command->result = command->arg1 * command->arg2;
	}
	else if(strcmp(command->operation, "/") == 0){
		command->result = command->arg1 / command->arg2;
	}
	else if(strcmp(command->operation, "%") == 0){
		command->result = command->arg1 % command->arg2;
	}
	else{
		command->result = (command->arg1 == 0)? 1:0;
	}
}
