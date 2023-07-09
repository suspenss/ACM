#include <stdio.h>

int process(char * str, int len) {
    char s[100];
    int i;
    for (i = 0; i < len; i++) {
        int cur = 1;
        s[i] = str[i];
        if (len % (i + 1) != 0)
            continue;
        for (int j = 0; j < len - i - 1; j++) {
            if (s[j % (i + 1)] != str[i + 1 + j]) {
                cur = 0;
                break;
            }
        }
        if (cur)
            return i + 1;
    }
    return i + 1;
}

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        char str[100], c;
        int i = 0;
        while (scanf("%c", &c) && c != '\n')
            str[i++] = c;
        if (n > 0)
            printf("%d\n\n", process(str, i));
        else
            printf("%d\n", process(str, i));
    }
}
