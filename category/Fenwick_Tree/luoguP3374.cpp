#include <iostream>
#include <vector>
typedef long long i64;

const int maxn = 5e5 + 10;
int n, q, a[maxn], t[maxn];

int lbit (int x) {
    return x & -x;
}

void add(int k, int x) {
    for (; k <= n; k += lbit(k)) t[k] += x;
}

int ask (int k) {
    int ans = 0;
    for (; k; k -= lbit(k)) ans += t[k];
    return ans;
}
void sol() {
    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        add(i, a[i]);
    }
    while (q--) {
        int op, a, b;
        std::cin >> op >> a >> b;
        if (op == 1) {
            add(a, b);
        } else {
            std::cout << ask(b) - ask(a - 1) << '\n';
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