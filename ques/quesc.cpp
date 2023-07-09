#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using i64 = int64_t;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector g(n, std::vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
        }
    }

    int a = g[0][0];
    for (int i = 0; i < n - 1; i++) {
        g[i][0] = g[i + 1][0];
    }

    for (int i = 0; i < n - 1; i++) {
        g[n - 1][i] = g[n - 1][i + 1];
    }
    for (int i = n - 1; i > 0; i--) {
        g[i][n - 1] = g[i - 1][n - 1];
    }
    for (int i = n - 1; i > 0; i--) {
        g[0][i] = g[0][i - 1];
    }

    g[0][1] = a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << g[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}