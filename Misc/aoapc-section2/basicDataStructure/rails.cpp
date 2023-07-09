#include <bits/stdc++.h>
#include <vector>
#include <stack>

int main () {
	int T, n;
	while (std::cin >> T && T) {
		std::vector<int> ord(T);
		while (std::cin >> n && n) {
			ord[0] = n;
			for (int i = 1; i < T; i++) {
				std::cin >> ord[i];
			} // data input
			std::stack<int> s;
			int idx = 0;
			for (int base = 1; base <= T; base++) {
				s.push(base);
				while (!s.empty() && s.top() == ord[idx]) {
					s.pop(), idx++;
				}
			}
			if (idx = T + 1 && s.empty()) std::cout << "Yes\n";
			else std::cout << "No\n";
		}
		std::cout << std::endl;
	}
}


// #include<bits/stdc++.h>
// using namespace std;
// int n, a[1010];
// int main() {
// 	while (cin >> n && n != 0) {
// 		while (cin >> a[1] && a[1] != 0) {
// 			for (int i = 2; i <= n; i ++)
// 				scanf("%d", &a[i]); // 输入
// 			stack<int> stk; // 模拟栈
// 			int j = 1; // 判断联系满足的个数
// 			for (int i = 1; i <= n; i ++) { // 1-n依次压入
// 				stk.push(i); // 压栈
// 				while (!stk.empty() && stk.top() == a[j])
// 					stk.pop(), j ++; // 当栈非空且栈顶为a[j]时，出栈
// 			}
// 			printf("%s\n", stk.empty() && j == n + 1 ? "Yes" : "No"); // 栈空表示合法
// 		}
// 		puts(""); // 两组间空行
// 	}
// 	return 0;
// }
