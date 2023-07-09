#include <iostream>
typedef long long i64;

const int maxn = 5e5 + 10;
int n, q, t[maxn], a[maxn];

int lbit (int x) {
    return x & -x;
}

void add (int k, int x) {
    for (; k <= n; k += lbit(k)) t[k] += x;
}

int ask (int k) {
    int ans = 0;
    for (; k; k -= lbit(k)) ans += t[k];
    return ans;
}

void sol() {
    std::cin >> n >> q;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> a[i];
    }
    while (q--) {
        int op, l, r, x;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r >> x;
            add(l, x), add(r + 1, -x);
        } else {
            std::cin >> x;
            std::cout << ask(x) + a[x] << '\n';
        }

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