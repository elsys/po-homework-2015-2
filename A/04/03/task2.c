#include <stdio.h>
#include <string.h>
char *get_result(char *res, char *state, char *oper)
{if(strcmp(state,"CLOSED") == 0 && strcmp(oper,"button_clicked") == 0)
    {strcpy(res,"OPENING");}
    else if(strcmp(state,"CLOSED") == 0 && strcmp(oper,"cycle_complete") == 0) 
{strcpy(res,"CLOSED");}
else if(strcmp(state,"OPENING") == 0 && strcmp(oper,"cycle_complete") == 0)
 {strcpy(res,"OPEN");}
else if(strcmp(state,"OPEN") == 0 && strcmp(oper,"button_clicked") == 0)
{strcpy(res,"CLOSING");}
else if(strcmp(state,"CLOSING") == 0 && strcmp(oper,"cycle_complete") == 0) 
{strcpy(res,"CLOSED");}
else if(strcmp(state,"OPENING") == 0 && strcmp(oper,"button_clicked") == 0)
 {strcpy(res,"STOPPED_WHILE_OPENING");}
else if(strcmp(state,"CLOSING") == 0 && strcmp(oper,"button_clicked") == 0) 
{strcpy(res,"STOPPED_WHILE_CLOSING");}
else if(strcmp(state,"STOPPED_WHILE_OPENING") == 0 && strcmp (oper,"button_clicked") == 0) 
{strcpy(res,"CLOSING");}
else if(strcmp(state,"STOPPED_WHILE_CLOSING") == 0 && strcmp(oper,"button_clicked") == 0) 
{strcpy(res,"OPENING");}
else if(strcmp(state,"OPEN") == 0 && strcmp(oper,"cycle_complete") == 0) 
    {strcpy(res,"OPEN");}
return res;
}
int main()
{char oper[22];
char res[22];
char state[22]="CLOSED";
char *get_res;
int l=0;


while(scanf("%s",oper)!=EOF)
{

get_res=get_result(res,state,oper);
strcpy(state,get_res);
if(l==0) {printf("Door: CLOSED\n");l=1;}
printf("Door: %s\n",get_res);}

return 0;
}
