#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BLUEBRIDGE = 933346
#define ALISON = 55583
#define FUN = 4210
#define PYRAMID = 01

int main(){

int dash_position = 0;
char isbn[20];
char filtered[13];
int publisher[7];
int filtered_digits[13];
int valid = 0;
int i,digit_counter=0,checksum,filter_count;
int s, reminder;


scanf("%s", &isbn);

if(isbn[0] == 57 && isbn[1] == 55 && (isbn[2] == 56 || isbn[2] == 57)){
	valid = 1;
}

if (valid != 1){
	printf("\n0");
	return 1;
}

filter_count = 0;
for(i=0; i=strlen(isbn); i++){
	if(isbn[i]>47 && isbn[i]<58){
		filtered[filter_count] = isbn[i];
		filter_count++; 
	}
}

if(filter_count != 13){
	printf("\n0");
	return 1;
}else {valid = 1;}


for(i=0; i<13; i++){
	filtered_digits[i] = atoi(filtered[i]);
}

s = filtered_digits[0] + filtered_digits[1]*3 + filtered_digits[2] + filtered_digits[3]*3 + filtered_digits[4] + filtered_digits[5]*3 + filtered_digits[6] + filtered_digits[7]*3 + filtered_digits[8] + filtered_digits[9]*3 + filtered_digits[10] + filtered_digits[11]*3 + filtered_digits[12];

reminder = s % 10;
checksum = 10 - reminder;

if(checksum != filtered_digits[12]){
	printf("\n0");
	return 1;
}else {valid = 1;}
 
for(i=6; i<strlen(isbn); i++){
	if(isbn[i] == 45){
		dash_position = i;
	}
}

filter_count = 0;
for(i=6; i=dash_position; i++){
	publisher[filter_count] = atoi(isbn[i]);
	filter_count ++;	
}

if(valid = 1){
printf("1");
}

return 0;
}
