#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int cmp(const void * a, const void * b) { return -(*(int *)a - *(int *)b); }
int main() {
    char s1[100], s2[100];
    while (scanf("%s %s", s1, s2) != EOF) {
        int a[28] = {0}, b[28] = {0};
        for (int i = 0; i < strlen(s1); i++)
            a[s1[i] - 'A']++;
        for (int i = 0; i < strlen(s2); i++)
            b[s2[i] - 'A']++;
        qsort(a, 27, sizeof(int), cmp);
        qsort(b, 27, sizeof(int), cmp);
        int flag = 1;
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                flag = 0;
                break;
            }
        }
        flag ? puts("YES") : puts("NO");
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
    }
    return 0;
}