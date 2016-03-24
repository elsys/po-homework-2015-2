#include <stdio.h>
#define MAX_SIZE 50

int* hop(int *);
int is_in_bound(int *, int , int *);

int main(){

    int ground[MAX_SIZE], counter = 0, *ptr, hops = 0;
    
    while(scanf("%d", &ground[counter]) != EOF && counter++ < 50 );
    
    ptr = &ground[0];
    
    do{
    
    	if(*ptr == '0'){
    	
    		printf("1\n");
    		break;
    	
    	}
    	
    	ptr = hop(ptr);
    	
    	hops++;
    	
    	if(!is_in_bound(ground, counter, ptr) || hops > 49){
    	
    		printf("0\n");
    		break;
    	
    	}
    
    }while(1);
    
    printf("%d\n", hops);
    
    return 0;
}

int* hop(int *elem){

	return (elem + *elem);

}

int is_in_bound(int *arr, int size, int *ptr){

	if(ptr - arr > 0 && ptr - arr < size){
	
		return 1;
	
	}

	return 0;

}
