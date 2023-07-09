#include <iostream>
#include <vector>
#include <algorithm>
typedef long long i64;
 
void sol() {
    int n, k;
    i64 ans = 1e18;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto & i : a) std::cin >> i;
 
    std::ranges::sort(a);
 
    int q[n + 1];
    for (int i = 1, hd = 0, tl = -1; i < n; i++) {
        if (tl >= hd && q[hd] - 1 < i - k + 1) hd += 1;
        while (tl >= hd && a[q[tl]] - a[q[tl] - 1] > a[i] - a[i - 1]) tl -= 1;
        q[++tl] = i;
        if (i + 1 >= k) {
            // std::cout << "HERE!";
            int maxx = a[i] - a[i + 1 - k];
            ans = std::min(ans, 1ll * maxx * (a[q[hd]] - a[q[hd] - 1]));
        }  
    }
 
    std::cout << ans << '\n';
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int T = 1;
    // std::cin >> T; // look at me, let's singing together
    while (T--) { 
        sol();
    }
 
    return 0;
}