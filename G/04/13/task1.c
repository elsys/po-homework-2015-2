#include <stdio.h>

int main(void) {
  char c;
  unsigned char i = 0;
  unsigned char error = 0;
  unsigned char hyphen = 0;
  unsigned char isbn[13];
  int publisher = 0;
  int sum = 0;
  unsigned char last;
  int check;
  while((c = getchar()) != '\n') {
    if((i == 0) && ((c < '0') || (c > '9'))) {
      error = 1;
      break;
    }
    if(i == 13) {
      error = 1;
      break;
    }
    if(c == '-') {
      hyphen++;
      continue;
    }
    if((c >= '0') && (c <= '9') && (i < 13)) {
      isbn[i++] = c - '0';
      if(hyphen == 2) {
        publisher = publisher * 10 + isbn[i - 1];
      }
    }
  }
  if(error) {
    printf("0\n");
    return 0;
  }
  if((isbn[0] != 9) && (isbn[1] != 7) && (isbn[2] < 8)) {
    printf("0\n");
    return 0;
  }
  for(i = 1; i < 13; ++i) {
    sum += (i % 2 == 0 ? 3 : 1) * isbn[i - 1];
  }
  last = 10 - (sum % 10);
  check = last == isbn[12];
  printf("%d\n", check);
  if(check) {
    switch(publisher) {
      case 933346:
        printf("Bluebridge\n");
        break;
      case 55583:
        printf("Alyson Books\n");
        break;
      case 4210:
        printf("FUNimation Productions, Ltd.\n");
        break;
      case 1:
        printf("Pyramid Books\n");
        break;
    }
  }

  return 0;
}
