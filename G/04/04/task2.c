#include <stdio.h>
#include <string.h>
int main(){
char garage[17];
char status[30];
int position = 0;
int digits[30]={0};
int count = 0;
int help =0;
while(scanf("%s", garage) != EOF){
if(!strcmp(garage, "button_clicked")){
if(position == 0){
position = 1;
digits[count]=position;
count++;
}
else if(position == 1){
position = 2;
digits[count]=position;
count++;
}
else if(position == 2){
position = 3;
digits[count]=position;
count++;
}
else if(position == 3){
position = 4;
digits[count]=position;
count++;
}
else if(position == 4){
position = 1;
digits[count]=position;
count++;
}
else if(position == 5){
position = 3;
digits[count]=position;
count++;
}
}
if(!strcmp(garage,"cycle_complete")){     
if(position == 1){
position = 5;
digits[count]=position;
count++;
}
else if(position == 3){
position = 0;
digits[count]=position;
count++;
}
}
}
printf("Door: CLOSED\n");
for(help=0;help<count;help++)
{
if(digits[help] == 0){
printf("Door: CLOSED\n");
}
if(digits[help] == 1){
printf("Door: OPENING\n");
}
if(digits[help] == 2){
printf("Door: STOPED_WHILE_OPENING\n");
}
if(digits[help] == 3){
printf("Door: CLOSING\n");
}
if(digits[help] == 4){
printf("Door: STOPED_WHILE_CLOSING\n");
}
if(digits[help] == 5){
printf("Door: OPEN\n");
}
}
return 0;
}
