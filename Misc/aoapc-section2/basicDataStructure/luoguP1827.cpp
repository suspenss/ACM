#include <iostream>
#include <string>
#include <unordered_map>

const int maxn = 30;
std::string in_order, pre_order;
std::unordered_map<char, int> pos;
std::unordered_map<char, char> l, r;

char build(int il, int ir, int pl, int pr) {
	char root = pre_order[pl];
	int k = pos[root];
	if (il < k) l[root] = build(il, k - 1, pl + 1, pl + k - il);
	if (k < ir) r[root] = build(k + 1, ir, pl + k - il + 1, pr);
	return root;
}

void dfs(char root) {
	if (l.count(root)) dfs(l[root]);
	if (r.count(root)) dfs(r[root]);
	std::cout << root;
}

int main () {
	std::cin >> in_order >> pre_order;
	for (int i = 0; i < in_order.size(); i++) pos[in_order[i]] = i;
	char root = build(0, in_order.size() - 1, 0, in_order.size() - 1);
	dfs(root);
	return 0;
}