#include<bits/stdc++.h>
using namespace std;

set<string> dic;
// stl set ，插入的元素就是排好序的， 比如字符串就是字典序

int main () {
	string s, buf;

	// cin 自动判断是否 EOF 所以不用写 ！= EOF（maybe）
	while (cin >> s) {

		// range 语法，简洁
		for (auto &c : s) {
			if (isalpha(c))
				c = tolower(c);
			else c = ' ';
			// 判断是否是字母，如果不是字母就替换为空格方便分割
		}
		// stringstream 流声明， 类似 haskell 的 words 函数
		stringstream ss(s);
		while (ss >> buf) // 记住 >> 的运算符
			dic.insert(buf);
	}
	// print
	for (auto word : dic)
		cout << word << endl;
	return 0;
}