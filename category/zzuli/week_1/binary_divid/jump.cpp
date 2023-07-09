#include <bits/stdc++.h>
using namespace std;

int blocks[100000];
int L, M, N;

bool ask(int len) {
    int cnt = 0;
    for (int i = 1, now = 0; i <= N; i++) {
        if (blocks[i] - blocks[now] < len) {
            cnt++;
        } else {
            now = i;
        }
    }
    if (cnt <= M) {
        return true;
    } else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> blocks[i];
    }
    blocks[N + 1] = L, blocks[0] = 0;
    int l = 1, r = L;
    while (l != r) {
        int mid = (l + r) / 2;
        // cout << "\nmid is here" << mid;
        if (ask(mid)) {
            l = mid + 1;
            // cout << mid;
            ans = mid;
        } else {
            r = mid - 1;
        }
        // cout << ans << " ";
    }
    cout << ans;
}
