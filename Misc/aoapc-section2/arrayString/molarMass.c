#include <ctype.h>
#include <stdio.h>
#include <string.h>

double map(char c) {
    switch (c) {
    case 'C':
        return 12.01;
    case 'H':
        return 1.008;
    case 'N':
        return 14.01;
    case 'O':
        return 16.00;
    }
    return 0;
}

void process(char * cs) {
    int cnt = 0, nowc = 0;
    double sum = 0;
    for (int i = 0; i < strlen(cs); i++) {
        if (isdigit(cs[i])) {
            cnt = cnt * 10 + cs[i] - '0';
        } else if (isalpha(cs[i]) &&
                   (isalpha(cs[i + 1]) || cs[i + 1] == '\n')) {
            sum += map(cs[i]);
        } else {
            sum += map(cs[nowc]) * cnt;
            nowc = i;
            cnt = 0;
        }
    }
    printf("%.3f\n", sum + map(cs[nowc]) * cnt);
    for (int i = 0; i < 100; i++) {
        cs[i] = '\0';
    }
}
int main() {
    int n;
    char single[100] = {'\0'};
    scanf("%d\n", &n);
    while (n--) {
        char c;
        int i = 0;
        while (scanf("%c", &c) == 1) {
            single[i++] = c;
            if (c == '\n') {
                process(single);
                break;
            }
        }
    }
}
