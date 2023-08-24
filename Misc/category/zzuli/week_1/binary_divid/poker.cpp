#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f;
int poker[52];
int n, joker;
bool judge(int x) {
    ll sm = 0;
    for (int i = 0; i < n; i++)
        if (poker[i] < x)
            sm += x - poker[i];
    return sm <= min(joker, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> joker;
    for (int i = 0; i < n; i++) {
        cin >> poker[i];
    }
    int l = 0, r = INF, ans = n;
    while (l <= r) {
        int mid = (l + r + 1) >> 1;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}
