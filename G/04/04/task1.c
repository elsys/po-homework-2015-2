#include<stdio.h>

#define EXIT_SUCCESS 1
#define WRONG_LENGTH -1
#define WRONG_START_VALUE -1
#define WRONG_INPUT -1
#define WRONG_CHECK_SUM -1

int is_correct_input(char *);
int is_correct_length(char *);
int is_correct_start_number(char *);
int parse_to_int(char * ,int *);
int check_last_digit(int *);
void publishing_house(int *);

int main() {
	char isbn_number[20] = {0};
	int parsed_isbn_number[20] = {0};
	
	scanf("%s",isbn_number);
	if(is_correct_input(isbn_number) == EXIT_SUCCESS && is_correct_length(isbn_number) == EXIT_SUCCESS &&
	   is_correct_start_number(isbn_number) == EXIT_SUCCESS){
	   
		parse_to_int(isbn_number ,parsed_isbn_number);
		if(check_last_digit(parsed_isbn_number) == EXIT_SUCCESS){
			printf("1\n");
			publishing_house(parsed_isbn_number);
			return 0;
		}	
	}
	printf("0\n");
	return 0;
}

int is_correct_length(char *isbn_number) {
	int position_counter = 0;
	while(isbn_number[position_counter] != '\0') {
		position_counter++;
	}
	if(position_counter < 17 || position_counter > 17) { 
		return WRONG_LENGTH;
	}
	return EXIT_SUCCESS;
}

int is_correct_start_number(char *isbn_number) {
	int position_counter = 0;
	int beggining_digits[20] = {0};
	
	while(isbn_number[position_counter] != '-') {
		beggining_digits[position_counter] = isbn_number[position_counter] - 48;
		position_counter++;
	}
	if(beggining_digits[0] != 9 || beggining_digits[1] != 7 || (beggining_digits[2] != 8 && beggining_digits[2] != 9)) {
		return WRONG_START_VALUE;
	}
	return EXIT_SUCCESS;
}

int is_correct_input(char *isbn_number) {
	int position_counter = 0;
	while(isbn_number[position_counter] != '\0') {
		if(isbn_number[position_counter] != '0' && isbn_number[position_counter] != '1' && 
		   isbn_number[position_counter] != '2' && isbn_number[position_counter] != '3' && 
		   isbn_number[position_counter] != '4' && isbn_number[position_counter] != '5' &&
		   isbn_number[position_counter] != '6' && isbn_number[position_counter] != '7' &&
		   isbn_number[position_counter] != '8' && isbn_number[position_counter] != '9' &&
		   isbn_number[position_counter] != '-' )  {
		   
		   return WRONG_INPUT;
		}
		position_counter++;
	}
	return EXIT_SUCCESS;
}

int parse_to_int(char *isbn_number ,int *parsed_isbn_number) {
	int position_counter = 0;
	
	while(isbn_number[position_counter] != '\0') {
		parsed_isbn_number[position_counter] = isbn_number[position_counter] - 48;
		position_counter++;
	}	
	return EXIT_SUCCESS;
}

int check_last_digit(int *parsed_isbn_number) {
	int position_counter = 0;
	int digit_result = 0;
	int final_result = 10;
	int multiplayer = 1; 
	
	while(position_counter <= 15) {
		if(parsed_isbn_number[position_counter] == -3) {
			position_counter++;
		}else {
			digit_result = digit_result + (parsed_isbn_number[position_counter] * multiplayer);
			position_counter++;
			if(multiplayer == 1) {
				multiplayer = 3;
		    }else {
		    	multiplayer = 1;
		    }
	    }
    }
	digit_result = digit_result % 10;
	final_result = final_result - digit_result;
	if(final_result == parsed_isbn_number[16]) {
		
		return EXIT_SUCCESS;
	}
	return WRONG_CHECK_SUM;	
}

void publishing_house(int *parsed_isbn_number) {
	int position_counter = 6;
	int counter = 0;
	int publishing_house_array[30] = {0};
	
	while(parsed_isbn_number[position_counter] != -3) {
		publishing_house_array[counter] = parsed_isbn_number[position_counter];
		//printf("%d",publishing_house_array[position_counter]);
		position_counter++;
		counter++;
	}
	if(publishing_house_array[0] == 5 && publishing_house_array[1] == 5 && publishing_house_array[2] == 5 &&
	   publishing_house_array[3] == 8 && publishing_house_array[4] == 3) {
		printf("Alyson Books\n"); 
		  
    }else if(publishing_house_array[0] == 9 && publishing_house_array[1] == 3 && publishing_house_array[2] == 3 &&
	   publishing_house_array[3] == 3 && publishing_house_array[4] == 4 && publishing_house_array[5] == 6) {
		printf("Bluebridge\n"); 
		  
	}else if(publishing_house_array[0] == 4 && publishing_house_array[1] == 2 && publishing_house_array[2] == 1 &&
	   publishing_house_array[3] == 0) {
		printf("FUNimation Productions, Ltd.\n");
			   
	}else if(publishing_house_array[0] == 0 && publishing_house_array[1] == 1) {
		printf("Pyramid Books\n");
	}
} 
