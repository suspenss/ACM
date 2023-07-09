// https://vjudge.net/problem/UVA-133#author=0
#include <stdio.h>

int main() {
    int n, m, k;
    while (scanf("%d %d %d", &n, &k, &m) == 3 && n) {
        int a[n + 2];
        a[0] = 0, a[n + 1] = 0;
        for (int i = 0; i < n + 1; i++)
            a[i] = 1;
        // 索引 0 和 索引 n+1 为起始位置， 标记为0
        // 其他位置标记为1
        int i = 0, j = n + 1, left = n;
        // i and j note the ri and rk,
        // 每次便利都会记录剩余人数，作为是否循环的判断条件
        while (left) {
            for (int t1 = 1; t1 <= k;) {
                i = i % n + 1;
                if (a[i])
                    t1++;
            }
            // 逆时针便利
            // i = i % n + 1; 确保循环遍历

            for (int t2 = 1; t2 <= m;) {
                j = (j + n - 2) % n + 1;
                if (a[j])
                    t2++;
            }
            // 顺时针

            printf("%3d", i);
            left--;
            if (i != j) {
                printf("%3d", j);
                left--;
            }
            if (left)
                printf(",");
            // 结果输出

            a[i] = 0, a[j] = 0;
            // 结果标记
        }
        printf("\n");
    }
    return 0;
}
