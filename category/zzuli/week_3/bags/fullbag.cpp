#include <iostream>
// 01 bag question : f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i])
// full bag question : f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i], f[i - 1][j - 2v[i]] + 2w[i] , ... , f[i - 1][j - kv[i]] + kw[i])
// cuz. f[i][j - v[i]] = max(f[i - 1][j - v[i]], f[i - 1][j - 2v[i] + w[i]], ... , f[i - 1][j - kv[i]] + (k - 1)w[i])
// res : f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])
const int maxn = 10010;
// int v[maxn], w[maxn];
// int f[maxn][maxn];
long long f[maxn];

int main () {
	int N, V;
	std::cin >> V >> N;
	for (int i = 1, v, w; i <= N; i++) {
		std::cin >> v >> w;
		for (int j = v; j <= V; j++) {
			f[j] = std::max(f[j], f[j - v] + w);
		}
	}
	std::cout << f[V] << '\n';
}

/*
int main () {
	int N, V;
	std::cin >> N >> V;
	for (int i = 1, v, w; i <= N; i++) {
		std::cin >> v >> w;
		for (int j = 0; j <= V; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= v) f[i][j] = std::max(f[i][j], f[i][j - v] + w);
		}
	}
	std::cout << f[N][V] << '\n';
}

*/