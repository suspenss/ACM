// https://www.luogu.com.cn/problem/P1638
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void process() {
    int n, m, tl = -1, hd = 0, r, l, cnt = 0, minlen = 1e9;
    std::cin >> n >> m;
    std::vector<int> a(n), hash(m + 2);
    for (auto & i : a) std::cin >> i;

    for (int i = 0, j = 0; i < n; i++) {
        if (hash[a[i]] == 0) cnt += 1;
        hash[a[i]] += 1;
        while (i >= j && hash[a[j]] > 1) hash[a[j]] -= 1, j += 1;
        if (cnt == m && i - j + 1 < minlen) l = j, r = i, minlen = i - j + 1;
    }
    std::cout << l + 1 << ' ' << r + 1;
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        process();
    }
}