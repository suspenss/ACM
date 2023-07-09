#include <bits/stdc++.h>
using namespace std;
// punctuation <, . ? : ; " '>
const int maxn = 1000 + 10;
int alignSize[200];
int main () {
	string line, buf;
	vector<string> lines[maxn];
	int linenumbers =  1;
	while (getline(cin, line)) {
		stringstream bufs(line);
		for (int j = 0; bufs >> buf; j++) {
			lines[linenumbers].push_back(buf);
			alignSize[j] = max((int)buf.size(), alignSize[j]);
		}
		linenumbers++;
	}
	for (int i = 1; i < linenumbers; i++) {
		for (int j = 0; j < (int)lines[i].size() - 1; j++)
			cout << left << setw(alignSize[j] + 1) <<  lines[i][j];
		cout << lines[i].back() << endl;
	}
}
// https://vjudge.net/problem/UVA-1593#author=wuyudi