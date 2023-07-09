#include <bits/stdc++.h>
using namespace std;

int main () {
	map<string, int> strm;
	string s;
	while (cin >> s) strm[s] = 1;

	for (auto &str : strm) {
		for (int i = 1; i < str.first.size(); i++) {
			if (strm.count(str.first.substr(0, i)) && strm.count(str.first.substr(i, str.first.size()))) {
				cout << str.first << endl;
				break;
			}
		}
	}
	return 0;
}