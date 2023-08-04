#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PII pair<int, int>
#define PLL pair<long long, long long>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
const int mod = 1e9 + 7;
const ll INF = 1e18;

int fa[N];
struct node {
    int x, y, v, k;
} a[N];

bool cmp(node a, node b) {
    return a.v < b.v;
}

int find(int n) {
    if (fa[n] != n) fa[n] = find(fa[n]);
    return fa[n];
}

void unionn(int x, int y) {
    int tx = find(x);
    int ty = find(y);
    fa[tx] = ty;
}

void solve() {
    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        a[i] = {x, y, v};
    }
    sort(a + 1, a + n + 1, cmp);

    cin >> m;
    while (m--) {
        for (int i = 1; i <= n; i++) fa[i] = i;
        int t;
        cin >> t;
        a[1].k = a[1].v * t;
        for (int i = 2; i <= n; i++) {
            a[i].k = a[i].v * t;
            for (int j = 1; j < i; j++) {
                int p = (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].x - a[j].x) * (a[i].x - a[j].x);
                int q = (a[i].k + a[j].k) * (a[i].k + a[j].k);
                if (q >= p) unionn(i, j);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) ans++;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}