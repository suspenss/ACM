#include <algorithm>
#include <iostream>
#define fst first
#define snd second
typedef long long i64;


const int maxn = 5e5 + 10;
int t[maxn], n;
std::pair<int, int> alls[maxn];

void insert (int x, int k) {
    for (; x <= n; x += x & -x) t[x] += k;
}

i64 query (int x) {
    i64 ans = 0;
    for (; x; x -= x & -x) ans += t[x];
    return ans;
}

void sol () {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> alls[i].fst, alls[i].snd = i;

    std::sort(alls + 1, alls + 1 + n, [](auto & a, auto & b) {
        if (a.fst != b.fst) return a.fst < b.fst;
        return a.snd < b.snd;
    });

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        insert(alls[i].snd, 1);
        ans += alls[i].snd - query(alls[i].snd);
    }
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