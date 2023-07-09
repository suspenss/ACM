#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q, cnt = 1;
	while (scanf("%d %d", &n, &q) && n) {
		cout << "CASE# " << cnt++ << ":\n";
		int a[n + 1], theq;
		for (int i = 0; i < n; ++i)	cin >> a[i];
		sort(a, a + n);
		while (q--) {
			cin >> theq;
			int l = -1, r = n;

			// binary search
			while (l + 1 != r) {
				int mid = (l + r) / 2;
				if (a[mid] >= theq) r = mid;
				else if (a[mid] < theq) l = mid;
			}

			// judge wether the key equal the found index
			if (a[r] == theq)
				cout << theq << " found at " << r + 1 << endl;
			else
				cout << theq << " not found\n";
		}
	}
}