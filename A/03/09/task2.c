#include <stdio.h>
#include <string.h>
#define INPUT_LENGTH 100
#define OPERATIONS 7

struct command_t {
    char operation[10];
    char arguments[2][10];
    int result;
    int success;
};

int exec_cmd(struct command_t*);
void parse_cmd(char*, struct command_t*);
int supported_operation(char*);
int number(char*);
int perform_operation(int, int, char*);
void print_result(struct command_t*, int);

int main() {
    
    char input[INPUT_LENGTH];
    struct command_t cmd;
    int code;
    
    while (fgets(input, INPUT_LENGTH + 1, stdin)) {
        parse_cmd(input, &cmd);
        code = exec_cmd(&cmd);
        print_result(&cmd, code);
        if (!feof(stdin)) {
            printf("\n");
        }
    }
    
    return 0;
}

int exec_cmd(struct command_t *cmd) {
    
    int arg1, arg2;

    if (!number(cmd->arguments[0]) && !number(cmd->arguments[1]) && !supported_operation(cmd->operation)) {
        cmd->success = 0;
        return -4;
    }

    if (supported_operation(cmd->operation)) {
        if (
            (strlen(cmd->operation) < 2) && 
            (strlen(cmd->arguments[0]) <= 0 || strlen(cmd->arguments[1]) <= 0) &&
            (strcmp(cmd->operation, "!") != 0)
        ) {
            cmd->success = 0;
            return -2;
        }
        
        if (
            (strlen(cmd->operation) >= 2) && 
            (strlen(cmd->arguments[0]) > 0 && strlen(cmd->arguments[1]) > 0)
        ) {
            cmd->success = 0;
            return -2;
        }
        
        if ((!number(cmd->arguments[0]) || !number(cmd->arguments[1])) && 
            strcmp(cmd->operation, "++") != 0 &&
            strcmp(cmd->operation, "!") != 0
        ) {
            cmd->success = 0;
            return -3;
        }
        
        if (strcmp(cmd->operation, "++") == 0 && number(cmd->arguments[1]) && strlen(cmd->arguments[0]) <= 0) {
            cmd->success = 0;
            return -4;
        } 
        
        sscanf(cmd->arguments[0], "%d", &arg1);
        sscanf(cmd->arguments[1], "%d", &arg2);
        
        if (strcmp(cmd->operation, "/") == 0 && arg2 == 0) {
            cmd->success = 0;
            return -5;
        }
        
        cmd->result = perform_operation(arg1, arg2, cmd->operation);
        
        if (cmd->result == 42) {
            cmd->success = 1;
            return -42;
        }
        
    } else {
        cmd->success = 0;
        return -1;
    }
    cmd->success = 1;
    return 0;
}

void parse_cmd(char *input, struct command_t *cmd) {
    
    char arguments[2][10] = {{ 0 }};
    char operation[10];
    
    sscanf(input, "%s %s %s", arguments[0], operation, arguments[1]);

    if (strcmp(operation, "++") == 0 && number(arguments[0]) && strlen(arguments[1]) <= 0) {
        arguments[0][0] = '\0';
        arguments[1][0] = '\0';
        sscanf(input, "%s %s %s", arguments[1], operation, arguments[0]);
    } else if (strlen(arguments[1]) == 0 && !supported_operation(operation)) {
        sscanf(input, "%s %s %s", operation, arguments[0], arguments[1]);
    }

    strcpy(cmd->arguments[0], arguments[0]);
    strcpy(cmd->arguments[1], arguments[1]);
    strcpy(cmd->operation, operation);
}

int supported_operation(char *operation) {
    
    const char operations[OPERATIONS][2] = { "+", "++", "-", "*", "/", "%", "!" };
    
    if (strlen(operation) > 2) {
        return 0;
    }
    
    for (int i = 0; i < OPERATIONS; i++) {
        if (operation[0] == '+' && operation[1] == '+') {
            return 1;
        }
        if (strcmp(operation, operations[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int number(char *string) {
    int length = strlen(string);
    if (length <= 0) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (string[i] < '0' || string[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int perform_operation(int arg1, int arg2, char *operation) {
    if (strcmp(operation, "+") == 0) {
        return arg1 + arg2;
    } else if (strcmp(operation, "++") == 0) {
        return ++arg1;
    } else if (strcmp(operation, "-") == 0 || (operation[0] == '+' && operation[1] == '+')) {
        return arg1 - arg2;
    } else if (strcmp(operation, "*") == 0) {
        return arg1 * arg2;
    } else if (strcmp(operation, "/") == 0) {
        return arg1 / arg2;
    } else if (strcmp(operation, "%") == 0) {
        return arg1 % arg2;
    } else if (strcmp(operation, "!") == 0) {
        return !arg1;
    }
    return 42;
}

void print_result(struct command_t *cmd, int code) {
    if (cmd->success == 1) {
        if (code == -42) {
            printf("the answer to life, the universe and everything else");
            return;
        }
        printf("%d", cmd->result);
    } else if (cmd->success == 0) {
        switch (code) {
            case -1:
                printf("operation not supported");
                return;
            case -2:
                printf("invalid command argument count");
                return;
            case -3:
                printf("invalid command arguments");
                return;
            case -4:
                printf("invalid input");
                return;
            case -5:
                printf("invalid arithmetic operation");
                return;
        }
    }
}