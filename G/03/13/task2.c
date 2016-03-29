#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct command_t {
    char* arg1;
    char* arg2;
    char* opt;
    char* result;
} command_t;

int count_format(char* line, int length) {
    int spaces = 0;
    int none_spaces;
    int i;
    for(i = 0; i < length; ++i) {
        if(line[i] == ' ') {
            spaces++;
            if((i > 0) && (line[i - 1] != ' ')) {
                none_spaces++;
            }
        }
    }
    return none_spaces - spaces;
}

int str_length(char* str) {
    if(str == NULL) {
        return -1;
    }
    int i;
    for(i = 0; str[i] != '\0'; ++i);
    return i;
}

int opt_code(char* opt) {
    int length = str_length(opt);
    int operator, i;
    if(length == 3) {
        char* not_supported_three_symbols = "<>";
        for(i = 0; i < 2; ++i) {
            if((opt[0] == opt[1]) && (opt[0] == not_supported_three_symbols[i]) && (opt[2] == '=')) {
                return 0;
            }
        }
    }
    if(length > 2) {
        return -1;
    }
    char* not_supported_two_symbols = "-=&|<>";
    operator = str_length(not_supported_two_symbols);
    for(i = 0; i < operator; ++i) {
        if((opt[0] == opt[1]) && (opt[1] == not_supported_two_symbols[i])) {
            return 0;
        }
    }
    char* not_supported_combined = "<>!&+-*/%^|";
    operator = str_length(not_supported_combined);
    for(i = 0; i < operator; ++i) {
        if((opt[0] == not_supported_combined[i]) && (opt[1] == '=')) {
            return 0;
        }
    }
    if((opt[0] == opt[1]) && (opt[1] == '+')) {
        return 1;
    }
    if(length > 1) {
        return -1;
    }
    char* not_supported = "=&|^";
    operator = str_length(not_supported);
    for(i = 0; i < operator; ++i) {
        if(opt[0] == not_supported[i]) {
            return 0;
        }
    }
    char* supported = "!+-*%/";
    operator = str_length(supported);
    for(i = 0; i < operator; ++i) {
        if(opt[0] == supported[i]) {
            return i + 2;
        }
    }
    return -1;
}

command_t fill(char* line, int length) {
    command_t command;
    int i, j, spaces;
    char token[length];
    int format = count_format(line, length);
    spaces = j = i  = 0;
    if((line[i] == ' ') && (format < 0)) {
        i++;
    }
    for(;i < length; ++i) {
        if(line[i] == ' ') {
            switch(spaces) {
                case 0: {
                    command.arg1 = (char*)malloc((j + 1) * sizeof (char));
                    strcpy(command.arg1, token);
                    command.arg1[j] = '\0';
                    break;
                }
                case 1: {
                    command.opt = (char*)malloc((j + 1) * sizeof (char));
                    strcpy(command.opt, token);
                    command.opt[j] = '\0';
                    break;
                }
            }
            j = 0;
            spaces++;
        } else {
            token[j++] = line[i];
        }
    }
    if(spaces == 1) {
        command.arg2 = (char*)malloc((j + 1) * sizeof (char));
        strcpy(command.arg2, token);
        command.arg2[j] = '\0';
        if(opt_code(command.arg2) > 0) {
            command.opt = command.arg2;
             command.arg2 = NULL;
        } else {
            command.opt = command.arg1;
            command.arg1 = NULL;
        }
    } else {
        command.arg2 = (char*)malloc((j + 1) * sizeof (char));
        strcpy(command.arg2, token);
        command.arg2[j] = '\0';
    }
    return command;
}

int parse_int(char* str, int* result) {
    int i = 0;
    int res = 0;
    int neg = 0;
    int length = str_length(str);
    if(length == -1) {
        return -1;
    }
    if(str[0] == '-') {
        i = 1;
        neg = 1;
    }
    for(;i < length; ++i) {
        if((str[i] < '0') || (str[i] > '9')) {
            return 1;
        }
        res *= 10;
        res += str[i] - '0';
    }
    if(neg == 1) {
        res *= -1;
    }
    *result = res;
    return 0;
}

int exec_cmd(command_t *cmd) {
    int arg1, arg2, cnv1, cnv2;
    int result;
    int opt = opt_code(cmd->opt);
    if(opt == -1) {
        return -4;
    }
    if(opt == 0) {
        return -1;
    }
    cnv1 = parse_int(cmd->arg1, &arg1);
    cnv2 = parse_int(cmd->arg2, &arg2);
    if((cnv1 == 1) || (cnv2 == 1)) {
        return -3;
    }
    if((opt < 3) && ((cnv1 == 0) && (cnv2 == 0))) {
        return -2;
    }
    if((opt < 3) && ((cnv1 == 0) && (cnv2 == -1))) {
        return -3;
    }
    if((opt >= 3) && ((cnv1 == -1) || (cnv2 == -1))) {
        return -2;
    }
    if((cnv1 == 0) && (cnv2 == 0)) {
        switch(opt) {
            case 3: {
                result = arg1 + arg2;
                break;
            }
            case 4: {
                result = arg1 - arg2;
                break;
            }
            case 5: {
                result = arg1 * arg2;
                break;
            }
            case 6: {
                if(arg2 == 0) {
                    return -5;
                }
                result = arg1 % arg2;
                break;
            }
            case 7: {
                if(arg2 == 0) {
                    return -5;
                }
                result = arg1 / arg2;
            }
        }
    } else {
        if(opt == 1) {
            result = 1 + arg2;
        }
        if(opt == 2) {
            result = !arg2;
        }
    }
    cmd->result = (char*)malloc(14 * sizeof (char));
    sprintf(cmd->result, "%d", result);
    return -9;
}

void add_error(struct command_t *cmd, int code) {
    switch(code) {
        case -1: {
            cmd->result = (char*)malloc(24 * sizeof (char));
            strcpy(cmd->result, "operation not supported");
            break;
        }
        case -2: {
            cmd->result = (char*)malloc(31 * sizeof (char));
            strcpy(cmd->result, "invalid command argument count");
            break;
        }
        case -3: {
            cmd->result = (char*)malloc(26 * sizeof (char));
            strcpy(cmd->result, "invalid command arguments");
            break;
        }
        case -4: {
            cmd->result = (char*)malloc(14 * sizeof (char));
            strcpy(cmd->result, "invalid input");
            break;
        }
        case -5: {
            cmd->result = (char*)malloc(29 * sizeof (char));
            strcpy(cmd->result, "invalid arithmetic operation");
            break;
        }
        case -42: {
            cmd->result = (char*)malloc(53 * sizeof (char));
            strcpy(cmd->result, "the answer to life, the universe and everything else");
            break;
        }
    }
}

void free_command (command_t* command) {
    free(command->arg1);
    free(command->opt);
    free(command->arg2);
    free(command->result);
}

void eval_command(char* line, int length) {
    command_t command = fill(line, length);
    int result = exec_cmd(&command);
    if(result < 0) {
        add_error(&command, result);
    }
    printf("%s\n", command.result);
    free_command(&command);
}

int main() {
    char c;
    char line[256];
    int i = 0;
    while(1) {
        c = getchar();
        if(c == '\n') {
            eval_command(line, i);
            i = 0;
        } else {
            if(c == EOF) {
                printf("\n");
                eval_command(line, i);
                break;
            }
            line[i++] = c;
        }
    }
    return 0;
}
