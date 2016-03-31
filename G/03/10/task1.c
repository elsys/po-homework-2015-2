#include <stdio.h>
#include <string.h>

int main(){

    char array[12];
    int string[10];
    int i;
    int month = 0;
    int days = 0;
    int year;

    scanf("%s", array);

    if(strlen(array) != 10){
        printf("0");
        return 0;
    }

    

    for(i=0; i < 10; i++){
        string[i] = (array[i] - 48);
    }
    year = string[0]*10 + string[1];
    month = string[2]*10 + string[3];
    days = string[4]*10 + string[5];
    if(year % 4 == 0){
if(month <= 12 && month > 0){
				if((month == 1) || (month == 3) || (month == 5) ||(month ==7) ||(month == 8) ||(month ==10)  || (month == 12)){
						if(days <= 31){
							printf("1\n");
							return 1;
						}
				}
				if((month == 4) || (month == 6) ||(month == 9) ||(month ==11)){
						if(days <= 30){
							printf("1\n");
							return 1;
						}
				}	
				if(month ==2){
					if(days <= 29){
							printf("1\n");
							return 1;
						}
				}


			}
		if(month <= 52 && month > 40){
		
			if((month == 41) || (month == 43) || (month == 45) ||(month ==47) ||(month == 48) ||(month ==50)  || (month == 52)){
						if(days <= 31){
							printf("1\n");
							return 1;
						}
				}
				if((month == 44) || (month == 46) ||(month == 49) ||(month ==51)){
						if(days <= 30){
							printf("1\n");
							return 1;
						}
				}	
				if(month ==42){
					if(days <= 29){
							printf("1\n");
							return 1;
						}
				}

		}
		printf("0\n");
	return 0;
		}
	if(year % 4 != 0){
		if(month <= 12 && month > 0){
				if((month == 1) || (month == 3) || (month == 5) ||(month ==7) ||(month == 8) ||(month ==10)  || (month == 12)){
						if(days <= 31){
							printf("1\n");
							return 1;
						}
				}
				if((month == 4) || (month == 6) ||(month == 9) ||(month ==11)){
						if(days <= 30){
							printf("1\n");
							return 1;
						}
				}	
				if(month ==2){
					if(days <= 28){
							printf("1\n");
							return 1;
						}
				}


			}
		if(month <= 52 && month > 40){
		
			if((month == 41) || (month == 43) || (month == 45) ||(month ==47) ||(month == 48) ||(month ==50)  || (month == 52)){
						if(days <= 31){
							printf("1\n");
							return 1;
						}
				}
				if((month == 44) || (month == 46) ||(month == 49) ||(month ==51)){
						if(days <= 30){
							printf("1\n");
							return 1;
						}
				}	
				if(month ==42){
					if(days <= 28){
							printf("1\n");
							return 1;
						}
				}

		}
		printf("0\n");
	return 0;
}
return 0;
}
