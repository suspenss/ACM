#include <iostream>
#include <vector>
typedef long long i64;

void sol() {
    int n, m;
    int hd = 0, tl = -1, maxinum = -1;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), q(m + 10);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1]; // 求前缀和数组 a[i]
    }

    for (int i = 0; i <= n; i++) {
        if (tl >= hd && i - q[hd] > m) hd += 1; // 保持队列长度在题目要求的范围内
        while (tl >= hd && a[q[tl]] > a[i]) tl -= 1; // 保证对头的元素是合法的且最小的
        q[++tl] = i; // 入队
        maxinum = std::max(maxinum, a[i] - a[q[hd]]); // 更新
    }
    std::cout << maxinum << '\n';
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