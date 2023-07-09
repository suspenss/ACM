#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct si {string s; int i;};
// 定义一个结构体，存储首个出现的原字符串和这个字符有序列的出现次数

set<string> ans; // 无需排序
map<string, si> ms;
// key storage the sorted string which is all in lower case
// value storage the first input string that process equal the key
// and i storage the count of key

int main () {
	string s;
	while (cin >> s) {
		if (s[0] == '#') break; // pause condition

		// build a sorted and all lowercase string
		string lows = s;
		for (auto &c : lows) c = tolower(c);
		sort(lows.begin(), lows.end());

		// if lows is existence the count of key plus one
		// or the value string equal s count plus one
		if (ms[lows].i == 0) ms[lows].s = s;
		ms[lows].i++;
	}
	for (auto im : ms) {
		if (im.second.i == 1) ans.insert(im.second.s);
	}
	for (auto si : ans) cout << si << endl;
}