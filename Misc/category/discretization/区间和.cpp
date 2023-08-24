// https://www.acwing.com/problem/content/105/
#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;

void sol() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> add(n), query(m);
    std::vector<int> alls(n);

    for (int i = 0, dis, x; i < n; i++) {
        std::cin >> dis >> x;
        add[i] = {dis, x}, alls[i] = dis;
    }
    for (int i = 0, l, r; i < m; i++) {
        std::cin >> l >> r;
        query[i] = {l, r}, alls.push_back(l), alls.push_back(r);
    }
    std::sort(alls.begin(), alls.end());
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

    std::vector<int> sum(alls.size() + 1);

    auto find = [&](int x) {
        return std::lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
    };

    for (auto [x, c] : add) {
        int dis = find(x);
        sum[dis] += c;
    }

    for (int i = 1; i <= alls.size(); i++) sum[i] += sum[i - 1];

    for (auto [l, r] : query) {
        int ll = find(l), rr = find(r);
        std::cout << sum[rr] - sum[ll - 1] << '\n';
    }
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