#include <stdio.h>

int ans[10];
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int k;
        scanf("%d", &k);

        for (int i = 1; i <= k; i++) {
            int temp = i;
            while (temp > 0) {
                ans[temp % 10]++;
                temp /= 10;
            }
        }
        for (int i = 0; i < 9; i++) {
            printf("%d ", ans[i]);
            ans[i] = 0;
        }
        printf("%d\n", ans[9]);
        ans[9] = 0;
    }
}
