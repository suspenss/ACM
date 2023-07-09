#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        char c;
        int sum = 0, cnt = 0;
        while (scanf("%c", &c) && c != '\n') {
            if (c == 'O')
                cnt++;
            else
                cnt = 0;
            sum += cnt;
        }
        printf("%d\n", sum);
    }
    return 0;
}
