#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char* data = malloc(20);
	int i;
	scanf("%s", data);
	if ( (data[0] == '9') && (data[1] == '7') && ((data[2] == '8') || (data[2] == '9')) ){
		int counter = 0;
		int check_sum = 0;
		int flag = 0;
		int last_digit = 0;
		int editor_house = 0;
		int is_in_house_editor_scope = 0;
		for (i = 0; i < strlen(data); i++){
			if (data[i] != '-'){
				counter += 1;
				if(is_in_house_editor_scope == 2){
					editor_house = 10*editor_house + (data[i] - '0');
				}
				if (flag){
					check_sum += (3*(data[i] - '0'));
					flag = 0;
				} else {
					check_sum += (data[i] - '0');
					flag = 1;
				}
				if(counter == 13){
					last_digit = (data[i] - '0');
					check_sum -= last_digit;
				}
			} else {
				is_in_house_editor_scope += 1;
			}
		}
		if ((counter == 13) && (10-(check_sum%10) == last_digit)){
			printf("1\n");
			if (editor_house == 933346){
				printf("Bluebridge\n");
				return 0;
			}
			if (editor_house == 55583){
				printf("Alyson Books\n");
				return 0;
			}
			if (editor_house == 4210){
				printf("FUNimation Productions, Ltd.\n");
				return 0;
			}
			if (editor_house == 1){
				printf("Pyramid Books\n");
				return 0;
			}
		} else {
			printf("0\n");
			return 0;
		}
	}
}