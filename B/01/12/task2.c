#include <stdio.h>
#include <string.h>

struct occurance_t {
	int times;
	int hash;
} current, best;

long hash (char *word);

int main () {
	char text[401], word[201];
	int count, zero, counter;

	scanf ("%[^\n]s", text);

	best.times = 0;
	best.hash = 0;

	for (count = 0; count < strlen (text); count++) {
	for (zero = 0; zero < 201; zero++) word[zero] = '0';

	for (zero = 0; text[count] != ' '; zero++, count++)
	word[zero] = text[count];

	if (word[zero - 1] == 'l') {
	if (word[zero - 2] == 'a') {
	if (word[zero - 3] == 's') {
	if (word[zero - 4] == 'i') {
	if (word[zero - 5] == 'm') {
	if (word[zero - 6] == 's') {
	if (word[zero - 7] == 'v') {
	break;
	}
	}
	}
	}
	}
	}
	}

	current.times = 1;
	current.hash  = hash (word);

	for (counter = count + 1; counter < strlen (text); counter++) {
	for (zero = 0; zero < 201; zero++) word[zero] = '0';

	for (zero = 0; text[counter] != ' '; zero++, counter++)
	word[zero] = text[counter];

	if (hash (word) == current.hash) current.times++;
	if (current.times > best.times) {
	best.times = current.times;
	best.hash = current.hash;
	}

	}

	}

	printf ("%d %d", best.times, best.hash);

	return 0;
}

long hash (char *word) {
	int sum = 42, count;

	for (count = 0; word[count] != '0'; count++) sum = sum + (word[count]) * (count + 1);

	return sum;
}

