#if !defined __TASK1__
#define __TASK1__


short strleng(char* word) {
	int i = 0;
	for(; word[i] != '\0'; i++) ;
	return i;
}

long hash(char* word) {
	int sum = 42;
	for(int i = 0; i < (int)strleng(word); i++)
		sum += word[i]*(i+1);
	return sum;
}

#endif