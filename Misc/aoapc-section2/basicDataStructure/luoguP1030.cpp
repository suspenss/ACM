#include <iostream>
#include <unordered_map>

const int maxn = 10;
std::string in_order, post_order;
std::unordered_map<char, int> pos;
std::unordered_map<char, char> l, r;

char build(int il, int ir, int pl, int pr) {
	char root = post_order[pr];
	int k = pos[root];
	if (il < k) l[root] = build(il, k - 1, pl, pl + k - il - 1);
	if (k < ir) r[root] = build(k + 1, ir, pl + k - il, pr - 1);
	return root;
}

void dfs_pre_order(char root) {
	std::cout << root;
	if (l.count(root)) dfs_pre_order(l[root]);
	if (r.count(root)) dfs_pre_order(r[root]);
}
int main () {
	std::cin >> in_order >> post_order;
	for (int i = 0; i < in_order.size(); i++) pos[in_order[i]] = i;
	char root = build(0, in_order.size() - 1, 0, in_order.size() - 1);
	dfs_pre_order(root);
}
/*
7
..*....
..*....
..*..*.
..*.*..
..**...
.....##
.*.****
*/