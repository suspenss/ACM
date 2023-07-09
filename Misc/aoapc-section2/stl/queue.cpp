#include <bits/stdc++.h>
using namespace std;
const int maxq = 1000 + 10;

int main () {
	int t, n, rank = 0, qnum, opnum;
	while (cin >> t && t) {
		cout << "Scenario #" << ++rank << endl;
		map<int, int> Qserial;
		for (int i = 0; i < t; i++) {
			cin >> n;
			while (n--) {
				cin >> qnum;
				Qserial[qnum] = i;
			}
		}

		// simulation
		string op;
		queue<int> q1, q[maxq];
		while (cin >> op && op[0] != 'S') {
			if (op[0] == 'E') {
				cin >> opnum;
				int f = Qserial[opnum];
				if (q[f].empty()) q1.push(f);
				q[f].push(opnum);
			} else if (op[0] == 'D') {
				int f = q1.front();
				cout << q[f].front() << endl;
				q[f].pop();
				if (q[f].empty()) q1.pop();
			}
		}
		cout << endl;

	}
	return 0;
}

// queue<int> a[t]
// when DEQUEUE, map<int, int> Qserial;
// f = Qserial[x] == the queuenumber;
// cout << a[f].front();
// a[f].pop()

// when ENQUEUE
// f = Qserial[x] == ...;
// a[f].push(x);