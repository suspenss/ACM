#include <iostream>
#include <algorithm>

const int maxn = 13000;
int N, V;
// int v[maxn], w[maxn];
// int f[maxn][maxn];
int dp[maxn];
// f[i][j] : 表示在取i个物品前， 不超过容量j 的最大价值
// f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i])
int main () {
	std::cin >> N >> V;
	for (int i = 1, v, w; i <= N; i++) {
		std::cin >> v >> w;
		for (int j = V; j >= v; j--) {
			dp[j] = std::max(dp[j - v] + w, dp[j]);
		}
	}
	std::cout << dp[V] << '\n';
}

// int main () {
// 	std::cin >> N >> V;
// 	for (int i = 1; i <= N; i++) std::cin >> v[i] >> w[i];

// 	for (int i = 1; i <= N; i++) {
// 		for (int j = 0; j <= V; j++) {
// 			f[i][j] = f[i - 1][j];
// 			if (j >= v[i]) f[i][j] = std::max(f[i][j], f[i - 1][j - v[i]] + w[i]);
// 		}
// 	}
// 	std::cout << f[N][V] << '\n';
// }
