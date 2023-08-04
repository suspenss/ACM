#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#pragma GCC optimize(2)

using i64 = int64_t;

struct DisjointSet {
    std::vector<int> f;

    DisjointSet() {}
    DisjointSet(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return false;

        f[fu] = fv;
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    std::cin >> N;

    std::vector<std::tuple<int, int, int, int>> info(N);
    for (auto &[x, y, v, t] : info) {
        std::cin >> x >> y >> v;
    }

    DisjointSet dsu;

    std::cin >> M;
    while (M--) {
        int T;
        std::cin >> T;

        dsu.init(N);

        for (int i = 0; i < N; i++) {
            auto &[x, y, v, t] = info[i];
            t = v * T;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                auto [x1, y1, v1, k1] = info[i];
                auto [x2, y2, v2, k2] = info[j];
                if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (k1 + k2) * (k1 + k2)) {
                    dsu.merge(i, j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += dsu.find(i) == i;
        }

        std::cout << ans << '\n';
    }

    return 0;
}