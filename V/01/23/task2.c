#include <stdio.h>
#include <string.h>

long hash(char* word);

struct occurance_t {
    long hash;
    long app;
};

int main() {
    char sentence[200];
    struct occurance_t base[200];
    int i;
    for(i = 0; i < 200; i++) {
        base[i].hash = 0;
        base[i].app = 0;
    }
    for(;;) {
        scanf("%s", sentence);
        if(!strcmp(sentence, "vsmisal"))
            break;
        int i;
        for(i = 0; base[i].hash != 0; i++) {
            if(hash(sentence) == base[i].hash) {
                base[i].app++;
                i = -1;
                break;
            }
        }
        if(i == -1)
            continue;
        else {
            base[i].hash = hash(sentence);
            base[i].app = 0;
        }
    }

    long search = 0;
    for(i = 0; base[i].hash != 0; i++) {
        if(search < base[i].app) {
            search = i;
        }
    }
    printf("%ld %ld", base[search].app + 1, base[search].hash);
    return 0;
}



long hash(char* word) {
    long hesh = (long)42, i;
    for(i = 0; i < strlen(word); i++) {
        hesh += (long)(word[i]*(i+1));
    }
    return hesh;
}
