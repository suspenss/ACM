#include <iostream>

const int maxn = 300 + 10;
int f[maxn][maxn];

int main () {
	int N, T, M;
	std::cin >> N >> T >> M;
	for (int i = 1, t, m; i <= N; i++) {
		std::cin >> t >> m;
		for (int j = T; j >= t; j--) {
			for (int k = M; k >= m; k--) {
				f[j][k] = std::max(f[j][k], f[j - t][k - m] + 1);
			}
		}
	}
	std::cout << f[T][M] << '\n';
}