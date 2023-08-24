#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
typedef long long i64;

void sol() {
    int n, k;
    i64 ans = 1e18;
    std::cin >> n >> k;

    std::multiset<int> ms; 
    std::vector<int> a(n + 1), dif(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    std::ranges::sort(a);
    
    for (int i = 1; i <= n; i++) dif[i] = a[i] - a[i - 1];

    for (int i = 2; i < k; i++) ms.insert(dif[i]);

    for (int i = k; i <= n; i++) {
        ms.insert(dif[i]);
        ans = std::min(ans, 1ll * (a[i] - a[i - k + 1]) * ( * ms.begin()));
        ms.erase(ms.find(dif[i - k + 2]));
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