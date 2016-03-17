#include<stdio.h>
#include<string.h>

char* find(char *haystack, char needle);

int main(){
	
	char array[400];
	char symbol;
	int index = 0, helper, breaker = 0;
	
	fgets(array , 400 , stdin);
	scanf("%c",&symbol);
	
	for( ; index < strlen(array) - 1 ; index++){
		helper = find(&array[index], symbol);
		if (helper == 1){
		printf("%d",index);
		breaker = 1;
		break;
		
		
		}
	}
	if (breaker == 0)printf("-1");

	
	return 0;
}

char* find(char *haystack, char needle){
	if(*haystack == needle)return 1;
	else return NULL; 

}
