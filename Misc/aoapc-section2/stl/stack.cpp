#include <bits/stdc++.h>

typedef std::set<int> Set;
std::vector<Set> Setcache;
std::map<Set, int> Idcache;

int getId(Set x) {
	if (Idcache.count(x)) return Idcache[x];
	Setcache.push_back(x);
	return Idcache[x] = Setcache.size() - 1;
}

int main () {
	int t, n;
	std::cin >> t;
	while (t--) {
		std::stack<int> s;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::string op;
			std::cin >> op;
			if (op[0] == 'P') s.push(getId(Set()));
			else if (op[0] == 'D') s.push(s.top());
			else {
				Set x1, x2, x;
				x1 = Setcache[s.top()]; s.pop();
				x2 = Setcache[s.top()]; s.pop();
				if (op[0] == 'A') {
					x = x2;
					x.insert(getId(x1));
				} else if (op[0] == 'U') set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), std::inserter(x, x.begin()));
				else if (op[0] == 'I') set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), std::inserter(x, x.begin()));
				s.push(getId(x));
			}
			std::cout << Setcache[s.top()].size() << '\n';
		}
		std::cout << "***\n";
	}
}