#include <iostream>
#include <cstring>
const int maxn = 10;
int sum[maxn];

void build(int p) {
	int v;
	std::cin >> v;
	if (v == -1) return;
	sum[p] += v;
	build(p - 1); build(p + 1);
}

bool init() {
	int v;
	std::cin >> v;
	if (v == -1) return false;
	std::memset(sum, 0, sizeof(sum));
	int p = maxn / 2;
	sum[p] = v;
	build(p - 1); build(p + 1);
	return true;
}

int main () {
	int rank = 0;
	while (init()) {
		std::cout << "Case " << ++rank << '\n';
		for (int i = 0; i < maxn; i++) {
			if (sum[i]) std::cout << sum[i] << ' ';
		}
		std::cout << "\n\n";
	}
	return 0;
}