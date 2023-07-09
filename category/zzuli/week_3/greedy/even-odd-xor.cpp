#include <iostream>

using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; cin >> n;
		int sum = 0;
		for (int i = 1; i < n - 2; i++) {
			printf("%d ", i);
			sum ^= i;
		}
		printf("%d %d ", (1 << 29), (1 << 30));
		printf("%d\n", sum ^ (1 << 29) ^ (1 << 30));
	}
	return 0;
}
/**/