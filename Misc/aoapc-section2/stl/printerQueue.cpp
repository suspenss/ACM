#include <bits/stdc++.h>
using namespace std;

int main () {
	int T, n, elem, tar;
	cin >> T;
	while (T--) {
		cin >> n >> tar;
		queue<pair<int, int>> q; priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			cin >> elem;
			if (i != tar) { q.push(make_pair(elem, 0)); }
			else q.push(make_pair(elem, 1));
			pq.push(elem);
		}
		int cnt = 0;
		while (1) {
			int prior = pq.top();
			pq.pop();
			while (q.front().first != prior) {
				pair<int, int> headp = q.front();
				q.pop();
				q.push(headp);
			}
			if (q.front().second) {
				cout << ++cnt << endl;
				break;
			}
			q.pop();
			cnt++;
		}
	}
}