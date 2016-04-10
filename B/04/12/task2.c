#include <stdio.h>
#include <string.h>

#define CLOSED 1
#define OPEN 2
#define CLOSING 3
#define OPENING 4
#define STOPPED_WHILE_CLOSING 5
#define STOPPED_WHILE_OPENING 6

int main () {
	char arr[15];
	int reminder[100], count = 0, status = 1, counter;


	char text1[] = "button_clicked";

	char text2[] = "cycle_complete";

	while (scanf ("%s", arr) != EOF) {

	if (status == CLOSED) {
	if (strcmp (text1, arr) == 0) {
	status = OPENING;
	reminder[count] = OPENING;
	count++;
	arr[0] = '0';
	}
	}

	if (status == OPEN) {
	if (strcmp (text1, arr) == 0) {
	status = CLOSING;
	reminder[count] = CLOSING;
	count++;
	arr[0] = '0';
	}
	}

	if (status == CLOSING) {
	if (strcmp (text1, arr) == 0) {
	status = STOPPED_WHILE_CLOSING;
	reminder[count] = STOPPED_WHILE_CLOSING;
	count++;
	arr[0] = '0';
	}

	if (strcmp (text2, arr) == 0) {
	status = CLOSED;
	reminder[count] = CLOSED;
	count++;
	arr[0] = '0';
	}
	}

	if (status == OPENING) {
	if (strcmp (text1, arr) == 0) {
	status = STOPPED_WHILE_OPENING;
	reminder[count] = STOPPED_WHILE_OPENING;
	count++;
	arr[0] = '0';
	}

	if (strcmp (text2, arr) == 0) {
	status = OPEN;
	reminder[count] = OPEN;
	count++;
	arr[0] = '0';
	}
	}

	if (status == STOPPED_WHILE_CLOSING) {
	if (strcmp (text1, arr) == 0) {
	status = OPENING;
	reminder[count] = OPENING;
	count++;
	arr[0] = '0';
	}
	}

	if (status == STOPPED_WHILE_OPENING) {
	if (strcmp (text1, arr) == 0) {
	status = CLOSING;
	reminder[count] = CLOSING;
	count++;
	arr[0] = '0';
	}
	}

	}

	printf ("Door: CLOSED\n");

	for (counter = 0; counter < count; counter++) {
	if (reminder[counter] == CLOSED) printf ("Door: CLOSED\n");
	if (reminder[counter] == OPEN) printf ("Door: OPEN\n");
	if (reminder[counter] == CLOSING) printf ("Door: CLOSING\n");
	if (reminder[counter] == OPENING) printf ("Door: OPENING\n");
	if (reminder[counter] == STOPPED_WHILE_CLOSING) printf ("Door: STOPPED_WHILE_CLOSING\n");
	if (reminder[counter] == STOPPED_WHILE_OPENING) printf ("Door: STOPPED_WHILE_OPENING\n");
 	}

	return 0;
}
