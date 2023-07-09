// https://vjudge.net/contest/552091#problem/C
#include <iostream>
#include <vector>
#define fst first
#define snd second
typedef long long i64;

std::vector<int> fa(1000), fb(1000);

int find(int x, auto & f) {
    if (f[x] != x) f[x] = find(f[x], f);
    return f[x];
}

void sol() {
    int n, m1, m2, cnt = 0;
    std::cin >> n >> m1 >> m2;

    std::vector<std::pair<int, int>> ans;

    for (int i = 1; i <= n; i++) fa[i] = fb[i] = i;

    for (int i = 0, u, v; i < m1; i++) {
        std::cin >> u >> v;
        fa[find(u, fa)] = find(v, fa);
    }

    for (int i = 0, u, v; i < m2; i++) {
        std::cin >> u >> v;
        fb[find(u, fb)] = find(v, fb);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int ia = find(i, fa), ib = find(i, fb);
            int ja = find(j, fa), jb = find(j, fb);
            if (ia != ja && ib != jb) {
                cnt += 1;
                ans.push_back({i, j});
                fa[ia] = ja, fb[ib] = jb;
            }
        }
    }
    std::cout << cnt << '\n';
    for (auto [u, v] : ans) std::cout << u << ' ' << v << '\n';
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