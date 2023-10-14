#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, _size;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        _size.assign(n, 1);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return false;

        f[fu] = fv;
        _size[fv] += _size[fu];
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int size(int x) {
        return _size[find(x)];
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, Q;
    std::cin >> N >> M >> Q;

    DSU dsu(N);
    std::vector<std::vector<int>> adj(N);

    for (int i = 0, u, v; i < M; i++) {
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        dsu.merge(u, v);
    }

    std::vector<int> diameter(N);

    auto dfs = [&](auto self, int u, int f) {
    };

    return 0;
}
