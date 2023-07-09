#include <bits/stdc++.h>
using namespace std;

int main () {
	string a;
	bool flag = false;
	while (getline(cin, a)) {
		for_each(a.begin(), a.end(), [&flag](char c) {
			if (c == '"') cout << ((flag = !flag) ? "``" : "''");
			else cout << c;
		});
		cout << endl;
	}
	return 0;
}