#include <iostream>
#include <list>

std::string s;
int main () {
	while (std::cin >> s) {
		std::list<char> l;
		auto p = l.begin();
		for (auto c : s) {
			if (c == '[') p = l.begin();
			else if (c == ']') p = l.end();
			else {
				p = l.insert(p, c); p++;
			}
		}
		for (auto c : l) std::cout << c;
		std::cout << std::endl;
	}
}


/*
// use array simulate link list
#include <bits/stdc++.h>
using namespace std;

int main () {
	string a;
	while (getline(cin, a)) {
		list<char> l;
		auto p = l.begin();
		for (auto c : a) {
			if (c == '[') p = l.begin();
			else if (c == ']') p = l.end();
			else { p = l.insert(p, c); p++; }
		}
		for (auto c : l) cout << c;
		cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10;
int main () {
	string a;
	while (cin >> a) {
		int next[maxn], cur = 0, last = 0;
		for (auto i = 1; i < a.size(); i++) {
			if (a[i] == '[') cur = 0;
			else if (a[i] == ']') cur = last;
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == last) last = i;
				cur = i;
			}
		}
		for (int i = next[0]; i != 0; i++) {
			cout << a[next[i] - 1];
		}
		cout << "\n";
	}
}
*/