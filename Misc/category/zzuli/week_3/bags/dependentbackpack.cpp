#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using i64 = long long;

const int maxn = 4e4 + 10;
int f[maxn];
std::unordered_map<int, std::vector<std::pair<int, int>>> hash;
std::vector<std::pair<int, int>> gs[65];

int main () {
	int V, N, cnt = 0;
	std::cin >> V >> N;
	V /= 10;
	for (int i = 1, v, p, q; i <= N; i++) {
		std::cin >> v >> p >> q;
		if (q == 0) gs[i].push_back(std::make_pair(v / 10, p * v));
		else hash[q].push_back(std::make_pair(v / 10, p * v));
	}
	for (auto [q, things] : hash) {
		if (gs[q].size() == 1) {
			int sumv = gs[q][0].first, sump = gs[q][0].second;
			for (int i = 0; i < things.size(); i++) {
				sumv += things[i].first;
				sump += things[i].second;
				gs[q].push_back({things[i].first + gs[q][0].first, things[i].second + gs[q][0].second});
			}
			gs[q].push_back(std::make_pair(sumv, sump));
		}
	}
	for (int i = 1; i <= 65; i++) {
		if (gs[i].size() == 0) continue;
		for (int j = V; j >= 1; j--) {
			for (auto thing : gs[i]) {
				if (j >= thing.first) f[j] = std::max(f[j], f[j - thing.first] + thing.second);
			}
		}
	}
	std::cout << f[V] << '\n';
}