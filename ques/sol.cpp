#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using i64 = int64_t;

void sol() {
    i64 n;
    std::cin >> n;

    for (int i = 2; i <= 60; i++) {
        i64 l = 1, r = 1e9 + 1;
        while (l + 1 != r) {
            i64 mid = (l + r) / 2;

            i64 sum = 0;
            for (int j = 0; j <= i and sum <= n; j++) {
                sum += std::pow(mid, j);
            }

            if (sum == n) {
                std::cout << "YES\n";
                return;
            } else if (sum < n) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    std::cin >> T;

    for (int _ = 0; _ < T; _++) {
        sol();
    }

    return 0;
}
