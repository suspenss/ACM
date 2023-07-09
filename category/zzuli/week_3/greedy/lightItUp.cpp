#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int maxn = 1e5 + 10;
std::vector<std::pair<int, int>> dis(maxn);
int main () {
	int n, M, ans = 0;
	std::cin >> n >> M;
	for (int i = 1, p; i < n; i++) {
		std::cin >> p;
		dis[i] = std::make_pair(p - dis[i - 1].first, i);
	}
	std::sort(dis.begin(), dis.begin() + n + 2, std::less());
	for (int i = 0; i < n + 2; i++) {
		if (dis[i].second % 2 == 0) {
			dis[i].first -= 1;
			dis[i].second
		}
	}
}