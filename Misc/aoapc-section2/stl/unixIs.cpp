#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, maxlen = 0;
	while (cin >> n) {
		cout << "------------------------------------------------------------" << endl ;
		vector<string> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			maxlen = max(maxlen, (int)v[i].size());
		}
		sort(v.begin(), v.end());
		int colums = (60 - maxlen) / (maxlen + 2) + 1, rows = (n - 1) / colums + 1;

		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < colums; c++) {
				int index = rows * c + r;
				if (index < n) {
					cout << v[index];
					if (c + 1 == colums) {
						for (int i = 0; i < maxlen - v[index].size(); i++) cout << " ";
					} else {
						for (int i = 0; i < maxlen  - v[index].size() + 2; i++) cout << " ";
					}
				}
			}
			cout << endl;
		}

	}
}
