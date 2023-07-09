#include <bits/stdc++.h>
using namespace std;

// 学习: 如果要判断某个序列元素的计算值一直是一个数,可以用  set 存储,最后判断 set的size 是否 为 1
int main () {
	int T, n, x, y;
	cin >> T;
	while (T--) {
		map<int, vector<int>> pois;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			pois[y].push_back(x);
		}
		set<int> ans;
		for (auto poi : pois) {
			sort(poi.second.begin(), poi.second.end());
			for (int i = 0; i < ceil(poi.second.size() * 1.0 / 2); i++) {
				ans.insert(poi.second[i] + poi.second[poi.second.size() - i - 1]);
				if (ans.size() > 1) break;
			}
			if (ans.size() > 1) break;
		}
		if (ans.size() == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}