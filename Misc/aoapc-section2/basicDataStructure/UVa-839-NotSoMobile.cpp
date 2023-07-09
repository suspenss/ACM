#include <iostream>

bool process(int & W) {
	int w1, d1, w2, d2;
	bool b1 = true, b2 = true;
	std::cin >> w1 >> d1 >> w2 >> d2;
	if (w1 == 0) process(w1);
	if (w2 == 0) process(w2);
	W = w1 + w2;
	return b1 && b2 && (w1 * d1 == w2 * d2);
}
int mian () {
	int T, W;
	std::cin >> T;
	while (T--) {
		if (process(W)) std::cout << "YES\n";
		else std::cout << "NO\n";
		if (T) std::cout << '\n';
	}
	return 0;
}