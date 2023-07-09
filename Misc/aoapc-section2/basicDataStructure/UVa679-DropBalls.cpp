#include <iostream>

int main () {
	int T, D, I;
	std::cin >> T;
	while (T--) {
		int ans = 1;
		std::cin >> D >> I;
		for (int i = 1; i < D; i++) {
			if (I % 2) {ans = ans * 2; I = (I + 1) / 2; }
			else {ans = ans * 2 + 1; I /= 2;}
		}
		std::cout << ans << '\n';
	}
}

// #include <bits/stdc++.h>
// using namespace std;

// int main () {
// 	int T, D, I, k, i; // initlization: D : depth, I : the quary number, k: the answer number
// 	cin >> T;
// 	while (T--) {
// 		cin >> D >> I;
// 		for (i = 1, k = 1; i < D; i++) {
// 			if (I % 2) k *= 2, I = (I + 1) / 2;
// 			else k = k * 2 + 1, I /= 2;
// 		}
// 		cout << k << endl;
// 	}
// }

// // 如果 I 为 4, 第四个从 root 出发， 第二个 (4 / 2) 向root 的右子树走去，所以此时可以将 root 的右子树 看作一个 root
// // 而 I = 4 / 2 = 2； 第二个 从 root 出发， 所以走向 右子树 。 此时将右子树看作root
// // I = 2 / 2 = 1； 第一个从 root 出发， 走向左子树，
// // I = （I + 1） / 2 = 1

// #include <bits/stdc++.h>
// using namespace std;

// const int maxd = 20;
// int node[1 << maxd];

// int main () {
// 	int D, I, T;
// 	cin >> T;
// 	while (T--) {
// 		cin >> D >> I;
// 		memset(node, 0, sizeof(node));
// 		int k, n = (1 << D) -  1;
// 		for (int i = 0; i < I; i++) {
// 			for (k = 1; k <= n; ) {
// 				node[k] = !node[k];
// 				k = node[k] ? 2 * k : 2 * k + 1;
// 			}
// 		}
// 		cout << k / 2 << endl;
// 	}
// 	cin >> T;
// 	return 0;
// }