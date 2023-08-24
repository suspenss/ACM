#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main () {
	int T, n, m, k;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k;
		std::vector<int> ct(m);
		std::map<int, int> mp;
		for (auto &i : ct) std::cin >> i, mp[i]++;
		int maxl = * std::max_element(ct.begin(), ct.end());
		if (maxl <= n / k) std::cout << "YES\n";
		else if (maxl == n / k + 1 && mp[maxl] <= n % k) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}