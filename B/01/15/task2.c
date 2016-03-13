#include <stdio.h>
#include <string.h>


struct occurance_t {
	int times;
	long hash;
}result;

long hash(char *);

int main() {

    int most_times = 0 ,counter , ok , word_hash;
    long str[3000][2];
   	long current_hash;
    char word[200];

	for(counter = 0; counter < 3000; counter++) {
		str[counter][0] = 0;
		str[counter][1] = 0;
	}

	do { scanf("%s", word);

     if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l')
     ok = 0;

		current_hash = hash(word);

		for(counter = 0; counter < 3000; counter++) {
			if(str[counter][0] == 0)
			{
				str[counter][0] = current_hash;
				str[counter][1]++;  counter = 3000;
			}
                else if(current_hash == str[counter][0])
                {
				str[counter][1]++;  counter = 3000;
                }
		}

	}while(ok);

	for(counter = 0; counter < 3000; counter++) {
		if(str[counter][1] > most_times)
		{
			word_hash = str[counter][0];
			most_times = str[counter][1];
		}
	}

    result.hash = word_hash ;
    result.times = most_times ;

	printf("%d %d", most_times, word_hash);

	return 0;
}

long hash(char *word){

int counter = 0 ,length , hash = 42;
length = strlen(word);

    for(;counter < length ; counter++){
        hash = hash + word[counter] * (counter+1);
    }

return hash;
}
