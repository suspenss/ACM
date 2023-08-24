#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long i64;

const int maxn = 5e4 + 10;
int f[maxn];
i64 dist[maxn];
int find(int x) {
    if (f[x] != x) {
        int u = find(f[x]);
        dist[x] += dist[f[x]];
        f[x] = u;
    }
    return f[x];
}

void sol() {
    int n, k, op, a, b, res = 0;
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) f[i] = i;

    while (k--) {
        std::cin >> op >> a >> b;
        int ida = find(a), idb = find(b);
        if (a > n || b > n) res += 1;
        else if (op == 1) {
            if (ida == idb && ( (dist[a] + 3) % 3 != (dist[b] + 3) % 3)) res += 1; // d[a] % 3 == d[b] % 3
            if (ida != idb) {
                f[ida] = idb;
                dist[ida] = dist[b] - dist[a];
            }
        } else {
            if (ida == idb && (dist[a] % 3 + 3) % 3 != ((dist[b] + 1) % 3 + 3) % 3) res += 1; // d[a] % 3 = d[b] % 3 + 1
            if (ida != idb) {
                f[ida] = idb;
                dist[ida] = dist[b] + 1 - dist[a];
            }
        }
    }
    std::cout << res << '\n';
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