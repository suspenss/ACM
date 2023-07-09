#include <bits/stdc++.h>
using namespace std;


void process() {
	int n;
	cin >> n;
	vector<int> tup(n);
	map<vector<int>, int> tmap;
	tup.reserve(n + 3);
	for (auto &i : tup) cin >> i;
	tup.push_back(tup.front());
	while (!tmap.count(tup)) {
		tmap[tup] = 1;
		for (int i = 0; i < n; i++) tup[i] = abs(tup[i + 1] - tup[i]);
		tup[n] = tup.front();
	}
	for (auto i : tup) if (i != 0) {
			cout << "LOOP\n";
			return;
		}
	cout << "ZERO\n";
}
int main () {
	int T;
	cin >> T;
	while (T--) {
		process();
	}
}