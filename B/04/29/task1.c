#include<stdio.h>
#include<string.h>

int valid_isbn(char *);
void type(char *);


int main(){

	char isbn[20];
	
	
	fgets(isbn, 20, stdin);
	printf("\n%d", valid_isbn(isbn));
	if (valid_isbn(isbn))type(isbn);
	

	return 0;
}

	int valid_isbn(char *isbn){

		//length validation
		
		if (strlen(isbn) - 1 != 16){
			
			return 0;
		}
		
		//first numbers
		
		if  (isbn[0] != '9'){
			
			return 0;
		}
			else if( isbn[1] != '7'){
				
				return 0;
			}
				else if(isbn[2] != '8' && isbn[2] != '9'){
					
					return 0;
				}
				
		
			
		//sum checker
		int index = 0;
		int counter = 0 , sum = 0 , checker = 1;
		
		for (; index < strlen(isbn) - 1; index++ ){
			if(isbn[index] != '-'){
			
				if (counter % 2 == 0){
					sum += (isbn[index] - '0') * 1;
				} 
				
				if (counter % 2 == 1){
					sum += (isbn[index] - '0') * 3;
				}
				counter++;
			}
		}
		
		sum = sum % 10;
		
		sum = 10 - sum;
		
		
		
			if ((isbn[16] - '0') != sum )checker = 0;
		return checker;
	}
	
	void type(char * isbn){
		int counter = 0, index = 0 , number = 0;
			for(;index < strlen(isbn) ; index++){
				if ( isbn[index] == '-')counter++;
				if (counter == 2)
					if (isbn[index] >= '0' && isbn[index] <= '9' ){
						number = (number * 10)  + (isbn[index] - '0');
					
					}
			}
			if (number == 933346)printf("\nBluebridge");
			if (number == 55583)printf("\nAlyson Books");
			if (number == 4210)printf("\nFUNimation Productions, Ltd.");
			if (number == 1)printf("\nPyramid Books");
			
			
	}
	
