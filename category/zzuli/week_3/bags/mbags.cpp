#include<iostream>
// using namespace std;
const int N = 1000010;
int n, m, x, y, z, cnt, f[N], w[N], v[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> x >> y >> z;
        for (int j = 1; j <= z; j <<= 1)
            v[++cnt] = x * j, w[cnt] = y * j, z -= j;
        if (z) v[++cnt] = x * z, w[cnt] = y * z;
    }

    for (int i = 1; i <= cnt; i++)
        for (int j = m; j >= w[i]; j--)
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
    std::cout << f[m] << '\n';
    return 0;
}
/*
int main () {
    int N, V;
    std::cin >> N >> V;
    for (int i = 1, v, w, c; i <= N; i++) {
        std::cin >> v >> w >> c;
        for (int k = 0; k < c; k++) {
            for (int j = V; j >= v; j--)
                f[j] = std::max(f[j], f[j - v] + w);
        }
    }
    std::cout << f[V] << '\n';
}
*/