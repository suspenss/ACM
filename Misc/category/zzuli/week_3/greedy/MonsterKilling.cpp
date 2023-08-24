#include <iostream>
#include <cstring>
#define max(a, b) (a > b ? a : b)

const int maxn = 2e5 + 10;
int bst[maxn], mons[maxn], pi, si, T, n, hs;

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		int maxmp = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> mons[i];
			maxmp = max(maxmp, mons[i]);
		}

		std::cin >> hs;
		for (int i = 0; i < hs; i++) {
			std::cin >> pi >> si;
			bst[si] = max(bst[si], pi);
		}
		for (int i = n; i >= 1; i--)
			bst[i] = max(bst[i], bst[i + 1]);
		if (maxmp > bst[1]) {
			std::cout << "-1\n";
		} else {
			int len = 0, ans = 1, Max = 0;
			for (int i = 0; i < n; i++) {
				Max = max(Max, mons[i]); len++;
				if (bst[len] >= Max) continue;
				len = 1; ans++; Max = mons[i];
			}
			std::cout << ans << '\n';
		}
		memset(bst, 0, sizeof(int) * n + 5);
	}
}