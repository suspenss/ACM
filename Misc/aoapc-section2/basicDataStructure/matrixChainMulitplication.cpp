#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	map<char, pair<int, int>> matrix;
	while (n--) {
		char name;
		int row, col;
		cin >> name >> row >> col;
		matrix[name] = {row, col};
	}
	string exp;
	while (cin >> exp) {
		if (exp.size()  == 1) cout << 0 << endl;
		else {
			char mark = 'a';
			stack<char> stk;
			long long ans = 0;
			int flag = 1;
			for (auto c : exp) {
				if (c == ')') {
					int r1 = matrix[stk.top()].first, c1 = matrix[stk.top()].second;
					stk.pop();
					int r2 = matrix[stk.top()].first, c2 = matrix[stk.top()].second;
					stk.pop(); stk.pop();
					if (r1 != c2) { cout << "error\n"; flag = 0; break; }
					else {
						ans += (r2 * c2 * c1);
						stk.push(++mark);
						matrix[mark] = {r2, c1};
					}
				} else stk.push(c);
			}
			if (flag) cout << ans << endl;
		}
	}
}