#include <math.h>
#include <stdio.h>

int todec(int * a, int len) {
    int dec = 0, tlen = len;
    for (int i = 0; i < len; i++)
        dec += a[i] * pow(2, --tlen);
    return dec;
}
void get(int * h, int len) {
    char c;
    int i = 0;
    while (i != len) {
        c = getchar();
        if (c >= '0' && c <= '9')
            h[i++] = c - '0';
    }
}

int main() {
    int ind[21] = {0};
    ind[0] = 0;
    for (int i = 1; i < 20; i++) 
        ind[i] = ind[i - 1] * 2 + 1;

    for (int i = 1; i < 20; i++)
        ind[i] += ind[i - 1];
    char in[1000] = {'\0'};
    while (fgets(in, 1000, stdin), in[0] != EOF) {
        int head[6] = {0};
        while (get(head, 3), 1) {
            int cnt = todec(head, 3);
            if (cnt == 0)
                break;
            // exit

            int sub[cnt + 2], su, sum = 0;
            for (int i = 0; i < cnt; i++) {
                sum += pow(2, i);
            }
            while (1) {
                get(sub, cnt);
                su = todec(sub, cnt);
                if (su == sum)
                    break;
                printf("%c", in[su + ind[cnt - 1]]);
            }

        }
            printf("\n");
            getchar();
    }
}
