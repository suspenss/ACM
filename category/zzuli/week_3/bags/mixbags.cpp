#include <iostream>
#include <algorithm>

const int maxn = 1000 + 10;
int N, V, f[maxn], vv, ww;

int main () {
	int x1, yy, x2, y2;
	scanf("%d:%d %d:%d", &x1, &yy, &x2, &y2);
	if (yy > y2)
	{
		y2 += 60;
		x2--;
	}
	V = (x2 - x1) * 60 + y2 - yy;
	scanf("%d", &N);
	for (int i = 1, v, w, c; i <= N; i++) {
		std::cin >> v >> w >> c;
		if (c != 0) {
			for (int j = 1; j <= c; j <<= 1) {
				vv = j * v;
				ww = j * w;
				c -= j;
				for (int j = V; j >= vv; j--) f[j] = std::max(f[j], f[j - vv] + ww);
			}
			if (c) {
				vv = c * v, ww = c * w;
				for (int j = V; j >= vv; j--) f[j] = std::max(f[j], f[j - vv] + ww);
			}
		} else {
			for (int j = v; j <= V; j++) f[j] = std::max(f[j], f[j - v] + w);
		}
	}
	std::cout << f[V] << '\n';
}