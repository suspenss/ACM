#include <iostream>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int, int> lch, rch;
int MAX = -1;

void dfs(int root, int depth) {
	if (lch.count(root)) dfs(lch[root], depth + 1);
	if (rch.count(root)) dfs(rch[root], depth + 1);
	MAX = std::max(depth, MAX);
}

int main () {
	int T, l, r;
	std::cin >> T;
	for (int i = 1; i <= T; i++) {
		std::cin >> l >> r;
		if (l != 0) lch[i] = l;
		if (r != 0) rch[i] = r;
	}
	dfs(1, 1);
	std::cout << MAX << '\n';
}