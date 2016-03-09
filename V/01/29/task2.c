#include <stdio.h>
#include <string.h>

struct occurance_t {
	int t;
	long hash;
};

long hash(char* word) {
    long hesh = (long)42, i;


    for(i = 0; i < strlen(word); i++)
        hesh += (long)(word[i]*(i+1));

    return hesh;
}


int main() {

	char text[100] = "";
	int size = 1;
	struct occurance_t model[100];
	memset(model, 0, sizeof(struct occurance_t));
	for(; strcmp(text, "vsmisal");) {
		scanf("%s", text);
		int j;
		for(j = 0; j < size; j++) {
			if(model[j].hash == hash(text)) {
				model[j].t++;
				break;
			}
			else
				continue;
		}
		if(j == size) {
			model[j].hash = hash(text);
			model[j].t = 1;
			size++;
		}
	}
	int n = 0;
	for(int i = 0; i < size; i++)
		if(model[i].t > n)
			n = i;
	printf("%d %ld", model[n].t, model[n].hash);

	return 0;
}