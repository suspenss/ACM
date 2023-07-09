#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, char> l, r;
int T;

void dfs_pre_order(char root) {
	std::cout << root;
	if (l.count(root)) dfs_pre_order(l[root]);
	if (r.count(root)) dfs_pre_order(r[root]);
}

int main () {
	std::cin >> T;
	char root, u;
	std::string buf;
	std::cin >> buf;
	root = buf[0];
	if (buf[1] != '*') l[root] = buf[1];
	if (buf[2] != '*') r[root] = buf[2];
	T--;
	while (T-- && std::cin >> buf) {
		u = buf[0];
		if (buf[1] != '*') l[u] = buf[1];
		if (buf[2] != '*') r[u] = buf[2];
	}
	dfs_pre_order(root);
	return 0;
}