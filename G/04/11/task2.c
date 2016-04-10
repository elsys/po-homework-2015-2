#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int b=0,c[100],i=0;
    char a[25];
    c[0]=0;
    while(scanf("%s",a) != EOF){
        if(strcmp(a,"button_clicked") == 0) b = 0;
        if(strcmp(a,"cycle_complete") == 0) b = 1;
        if(b==0){
            if(c[i]==0) c[i+1] = 1;
            if(c[i]==1) c[i+1] = 2;
            if(c[i]==2) c[i+1] = 4;
            if(c[i]==3) c[i+1] = 1;
            if(c[i]==4) c[i+1] = 3;
            if(c[i]==5) c[i+1] = 4;
        }
        if(b==1){
            if(c[i]==1) c[i+1] = 5;
            if(c[i]==4) c[i+1] = 0;
        }
        i++;
    }
    for(b=0;b<=i;b++) {
        if(c[b]==0) printf("Door: CLOSED\n");
        if(c[b]==1) printf("Door: OPENING\n");
        if(c[b]==2) printf("Door: STOPPED_WHILE_OPENING\n");
        if(c[b]==3) printf("Door: STOPPED_WHILE_CLOSING\n");
        if(c[b]==4) printf("Door: CLOSING\n");
        if(c[b]==5) printf("Door: OPEN\n");
    }
    return 0;
}
