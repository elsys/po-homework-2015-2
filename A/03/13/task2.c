#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct command_t
{
    char arg1[10];
    char arg2[10];
    char oper[3];
    long result;

};
void print_errors(int result, struct command_t cmd);
char readUntilSpace(char *string);
int is_oper(char *string);
int exec_cmd(struct command_t *cmd);
int is_number(char string[]);


int main()
{
    int space = 0, newline = 0, i = 0;
    char c, string[10];
    struct command_t com[100];
    long result = 0;

    for(i = 0; i < 100; i++)
    {
        com[newline].arg1[0] = '\0';
        com[newline].arg2[0] = '\0';
        com[newline].oper[0] = '\0';
    }

    while(c != EOF)
    {

        c = readUntilSpace(string);
        if(c == ' ')
        {
            space++;
            if(space == 1) {
                if(is_oper(string) == 1)
                {
                    strcpy(com[newline].oper, string);
                }
                else
                {
                     strcpy(com[newline].arg1, string);
                }
            }
            else if(space == 2)
            {
                strcpy(com[newline].oper, string);
            }
        }
        else if(c == '\n')
        {
            if(is_oper(string) == 1)
            {
                strcpy(com[newline].oper, string);
            }
            else
            {
                 strcpy(com[newline].arg2, string);
            }
            newline++;
            space = 0;
        }
    }

    for(i = 0; i < newline; i++)
    {
        result = exec_cmd(&com[i]);
        print_errors(result, com[i]);
    }

    return 0;
}

char readUntilSpace(char *string)
{
    char c;
    int i = 0;
    while(1)
    {
        c = getchar();
        if(c == ' ' || c == '\n' || c == EOF) {
            string[i] = '\0';
            return c;
        }
        string[i] = c;
        i++;
    }
}

int is_oper(char *string)
{
    int result = (strcmp("+", string) == 0 ||
                   strcmp("++", string) == 0 ||
                   strcmp("-", string) == 0 ||
                   strcmp("/", string) == 0 ||
                   strcmp("*", string) == 0 ||
                   strcmp("!", string) == 0 ||
                   strcmp("%", string) == 0 );

    return result;
}

int exec_cmd(struct command_t *cmd)
{
    /*if(is_number(cmd->arg1) == 0 || (is_oper(cmd->arg2[0]) != '\0' && is_number(cmd->arg1) == 0))
    {
        return -3;
    }*/
    if(!(is_number(cmd->arg1) == 1 && is_oper(cmd->oper)== 1 && is_number(cmd->arg1) == 1))
    {
        return -4;
    }
    if(cmd->arg2[0] == '\0')
    {
        return -2;
    }
    if(is_oper(cmd->oper) == 0)
    {
        return -1;
    }

    long arg1 = 0, arg2 = 0;
    if(is_number(cmd->arg1) == 1)
    {
        arg1 = strtol(cmd->arg1, NULL, 10);
    }
    else
    {
        return -3;
    }

    if(is_number(cmd->arg2) == 1)
    {
        arg2 = strtol(cmd->arg2, NULL, 10);
    }
    else
    {
        return -3;
    }
    if((atof(cmd->arg1) - strtol(cmd->arg1, NULL, 10)) != 0 || (atof(cmd->arg2) - strtol(cmd->arg2, NULL, 10)) != 0)
    {
        return -3;
    }

    if(strcmp("++", cmd->oper) == 0)
    {
        cmd->result = ++ arg2;
    }
    else if(strcmp("+", cmd->oper) == 0)
    {
        cmd->result = arg1 + arg2;
    }
    else if(strcmp("-", cmd->oper) == 0)
    {
        cmd->result = arg1 - arg2;
    }
    else if(strcmp("*", cmd->oper) == 0)
    {
        cmd->result = arg1 * arg2;
    }
     else if(strcmp("!", cmd->oper) == 0)
    {
        if(cmd->arg1[0] != '\0')
        {
            return -2;
        }
        if(cmd->arg2[0] == '\0')
        {
            return -4;
        }
        cmd->result = ! arg2;
    }
    else if(strcmp("/", cmd->oper) == 0)
    {
        if(arg2 == 0)
        {
            return -5;
        }
        else
        {
            cmd->result = arg1 / arg2;
        }

    }
    else if(strcmp("%", cmd->oper) == 0)
    {
        cmd->result = arg1 % arg2;
    }

    if(cmd->result == 42)
    {
        return -42;
    }
    else
    {
        return 0 ;
    }

}

void print_errors(int result, struct command_t cmd)
{
    if(result == -1)
    {
        printf("operation not supported");
    }
    else if(result == -2)
    {
        printf("invalid command argument count");
    }
    else if(result == -3)
    {
        printf("invalid command arguments");
    }
    else if(result == -4)
    {
        printf("invalid input");
    }
    else if(result == -5)
    {
        printf("invalid arithmetic operation");
    }
    else if(result == -42)
    {
        printf("the answer to life, the universe and everything else");
    }
    else if(result ==0)
    {
        printf("%ld", cmd.result);
    }
    printf("\n");
}

int is_number(char string[])
{
    char c = string[0];
    int i = 0;
    while(c != '\0')
	{
	int ci = c;
        if(isdigit(ci) == 0) {
            return 0;
        }
        c = string[i];
        i++;
    }

    return 1;
}

