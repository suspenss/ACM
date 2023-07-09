#include <bits/stdc++.h>
using namespace std;
// redundant
typedef int ID;
map<string, ID> Idcache;

int getId(string & a) {
	if (!Idcache.count(a)) Idcache[a] = Idcache.size();
	return Idcache[a];
}
void process(int n, int m) {
	string info, buf;
	Idcache.clear();
	int infomartix[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		int j = 1;
		getline(cin, info);
		stringstream infos(info);
		while (getline(infos, buf, ',')) infomartix[i][j++] = getId(buf);
	}
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			map<pair<int, int>, int> idmap;
			for (int r = 1; r <= n; r++) {
				pair<int, int> ids = make_pair(infomartix[r][i], infomartix[r][j]);
				if (idmap.count(ids)) {
					cout << "NO\n" << idmap[ids] << " " << r << "\n" << i << " " << j << endl;
					return;
				} else {
					idmap[ids] = r;
				}
			}
		}
	}
	cout << "YES\n";
	return;
}

int main () {
	int n, m;
	while (cin >> n >> m) {
		cin.get();
		process(n, m);
	}
	return 0;
}