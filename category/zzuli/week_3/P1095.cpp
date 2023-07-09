#include <iostream>
#include <algorithm>

const int N = 3e5 + 10;
int f[N];

int main () {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);
	int M, S, T;
	bool flag = true;
	std::cin >> M >> S >> T;
	f[0] = 0;
	for (int i = 1; i <= T; i++) {
		if (M >= 10) {
			f[i] = f[i - 1] + 60;
			M -= 10;
		} else {
			M += 4;
			f[i] = f[i - 1];
		}
	}
	int i;
	for (i = 1; i <= T; i++) {
		f[i] = std::max(f[i], f[i - 1] + 17);
		if (f[i] >= S) {
			flag = false;
			break;
		}
	}
	if (!flag) std::cout << "Yes\n" << i << std::endl;
	else std::cout << "No\n" << f[T] << std::endl;
}


// #include <iostream>
// #include <algorithm>
// #include <cstring>
// typedef long long i64;

// const int N = 31;
// i64 f[N][N][N][N][N];

// int main () {
// 	int n;
// 	while (std::cin >> n && n) {
// 		int s[5] = {0};
// 		for (int i = 0; i < n; i++) std::cin >> s[i];
// 		// memset(f, 0, sizeof f);
// 		f[0][0][0][0][0] = 1;

// 		for (int a = 0; a <= s[0]; a++) {
// 			for (int b = 0; b <= std::min(a, s[1]); b++) {
// 				for (int c = 0; c <= std::min(b, s[2]); c++) {
// 					for (int d = 0; d <= std::min(c, s[3]); d++) {
// 						for (int e = 0; e <= std::min(d, s[4]); e++) {
// 							i64 &x = f[a][b][c][d][e];
// 							if (a || b || c || d || e ) x = 0;
// 							if (a && a - 1 >= b) x += f[a - 1][b][c][d][e];
// 							if (b && b - 1 >= c) x += f[a][b - 1][c][d][e];
// 							if (c && c - 1 >= d) x += f[a][b][c - 1][d][e];
// 							if (d && d - 1 >= e) x += f[a][b][c][d - 1][e];
// 							if (e) x += f[a][b][c][d][e - 1];
// 						}
// 					}
// 				}
// 			}
// 		}
// 		std::cout << f[s[0]][s[1]][s[2]][s[3]][s[4]] << '\n';
// 	}
// }