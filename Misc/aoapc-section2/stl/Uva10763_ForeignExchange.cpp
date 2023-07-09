#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	vector<int> a, b;
	while (cin >> n && n) {
		a.clear(); b.clear();
		for (int i = 0; i < n; i++) {
			int go, co;
			cin >> go >> co;
			a.push_back(go); b.push_back(co);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a == b) cout << "YES\n";
		else cout << "NO\n";
	}
}