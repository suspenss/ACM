#include <iostream>
#include <algorithm>
#include <vector>
typedef long long i64;

const int maxn = 5e5 + 10;
int n, tl[maxn], tr[maxn], lef[maxn], rig[maxn];

void insert (int * t, int x, int k) {
    for (; x <= n; x += x & -x) t[x] += k;
}

i64 query (int * t, int x) {
    i64 ans = 0;
    for (; x ; x -= x & -x) ans += t[x];
    return ans;
}

void sol () {
    std::cin >> n;
    std::vector<int> alls(n), a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i], alls[i] = a[i];

    std::ranges::sort(alls);
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

    auto get_pos = [&](int k) {
        return std::lower_bound(alls.begin(), alls.end(), k) - alls.begin() + 1;
    };

    for (int i = 0; i < n; i++) {
        int pos = get_pos(a[i]);
        insert(tl, pos, 1);
        lef[i] = query(tl, pos - 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        int pos = get_pos(a[i]);
        rig[i] = n - i - 1 - query(tr, pos);
        insert(tr, pos, 1);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans += lef[i] * rig[i];

    std::cout << ans << '\n';
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