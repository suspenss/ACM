#include <stdio.h>
#include <string.h>

char str[100005], ttr[100005];
int solve(char * s, char * t) {
    int j = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (t[j] == s[i]) {
            j++;
        }
    }
    return j == strlen(t);
}
int main() {
    while (scanf("%s %s", ttr, str) != EOF) {
        solve(str, ttr) ? puts("YES") : puts("NO");
    }
    return 0;
}
