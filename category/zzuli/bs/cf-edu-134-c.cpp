#include <iostream>
#include <algorithm>
#pragma GCC optimize(3,"Ofast","inline")
typedef long long i64;

const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn], c[maxn];

bool check(int idx, int x) {
    for (int i = x; i > idx; i--) {
        if (a[i] > b[i - 1]) return false;
    }
    return true;
}


void sol() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];

    for (int i = 1; i <= n; i++) {
        auto it = *std::lower_bound(b + 1, b + n, a[i]) - a[i];
        std::cout << it << ' ';
    }
    std::cout << '\n';
    int l, lst = n + 1;
    for (int i = n; i >= 1; --i) {
        l = std::lower_bound(b + 1, b + n, a[i]) - b;
        if (l == i) {
            for (int i = l; i < lst; i++) c[i] = b[lst - 1] - a[i];
            lst = l;
        }
    }
    for (int i = 1; i <= n; i++) std::cout << c[i] << ' ';
    std::cout << '\n';
}




int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T--) {
        sol();
    }

    return 0;
}