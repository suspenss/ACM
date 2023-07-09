// https://www.luogu.com.cn/problem/P1419
#include <iostream>
#include <cmath>
#include <vector>
#define inf 0x3f3f3f

typedef long long i64;

const int maxn = 1e5 + 10;
double a[maxn], sum[maxn];
int q[maxn];
int n, s, t;

bool check(double x) {
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i] - x; // 求前缀和
    int hd = 0, tl = -1; // 初始化

    // 这道题其实是一道经典的单调队列的题,除了限制了"滑动窗口的窗口最大长度", 也限制了最小长度
    // 所以直接从 i = s 开始迭代, 入队和单调性优化时要修正为 i - s
    // 但是判断时不需要改为 i - s,
    // 即 对于每一个 i := i ∈ [s, n] (当i = s 时, 是最初状态,因为窗口长度有最小值)
    // 实际上, 如果没有窗口最小值, 即是[i - max, i] 区间的单调队列元素, 此时 q[hd] 是 [i - max, i] 区间的最小值
    // 可以求出 [i - max, i] 区间的最大和
    // 而加上了窗口最小值, 那个可以存在最小值的区间就成了 [i - max. i - min]
    for (int i = s; i <= n; i++) {
        while (tl >= hd && sum[q[tl]] > sum[i - s]) tl -= 1; // 单调性优化
        q[++tl] = i - s; // 入队
        while (tl >= hd && i - q[hd] > t) hd += 1; // 保证队列中元素索引的范围
        if (sum[i] - sum[q[hd]] >= 0) return true; // 判断
    }
    return false;
}

void sol() {
    std::cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    double l = -10000, r = 10000;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.3f\n", r);
}




int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        sol();
    }

    return 0;
}