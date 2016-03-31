#include <stdio.h>
#include <string.h>

int main()
{
    char egn[12];
    int stop[13],count,help=1,sum[10];

    scanf("%s", egn);
    help = strlen(egn);

    if (help != 10) stop[12] = 1;

    if (egn[0] < '0' && egn[0]>'9')  stop[0] = 1;

    if (egn[1] < '0' && egn[1]>'9')  stop[1] = 1;

    if ((egn[2] == '0' && egn[3] == '0') || (egn[2] == '2' && egn[3] == '0')) stop[2] = 1;
    if (egn[2] == '1' && egn[3] > '2') stop[3] = 1;
    if (egn[2] > '5') stop[4] = 1;
    if (egn[2] == '3' && egn[3] > '2') stop[5] = 1;
    if (egn[2] == '5' && egn[3] > '2') stop[6] = 1;

    if (egn[4] < '0' && egn[4]>'9')  stop[7] = 1;

    if (egn[5] < '0' && egn[5]>'9')  stop[8] = 1;

    if (egn[6] < '0' && egn[6]>'9')  stop[9] = 1;

    if (egn[7] < '0' && egn[7]>'9')  stop[10] = 1;

    if (egn[8] < '0' && egn[8]>'9')  stop[11] = 1;

    for(count = 0 ;count < 10 ;count++){
    if (egn[count] == '0') sum[count] = 0;
    if (egn[count] == '1') sum[count] = 1;
    if (egn[count] == '2') sum[count] = 2;
    if (egn[count] == '3') sum[count] = 3;
    if (egn[count] == '4') sum[count] = 4;
    if (egn[count] == '5') sum[count] = 5;
    if (egn[count] == '6') sum[count] = 6;
    if (egn[count] == '7') sum[count] = 7;
    if (egn[count] == '8') sum[count] = 8;
    if (egn[count] == '9') sum[count] = 9;
    }
sum[10] = (sum[0] * 2 + sum[1] * 4 + sum[2] * 8 + sum[3] * 5 + sum[4] * 10 + sum[5] * 9 + sum[6] * 7 + sum[7] * 3 + sum[8] * 6)%11;
if (sum[10] == 10) sum[10]= 0;

if (sum[10] != sum[9]) stop[13]=1;

    for (count = 0,help=1; count < 14;count++){
        if (stop[count] == 1) {
                help = 0;
        }
    }
    printf("\n%d",help);

return 0;
}
