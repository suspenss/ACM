#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	while (cin >> n && n) {
		vector<int> inp(n), disc;
		inp.reserve(2 * n); disc.reserve(n);
		for (int i = 1; i <= n; i++) inp[i - 1] = i;
		for (int i = 0; i < n - 1; i++) {
			disc.push_back(inp[i * 2]);
			inp.push_back(inp[(i * 2) + 1]);
		}
		cout << "Discarded cards:";
		if (!disc.empty()) cout << " " << disc[0];
		for (int i = 1; i < disc.size(); i++) {
			cout << ", " << disc[i];
		}
		cout << "\nRemaining card: " << inp.back() << endl;
	}
}
