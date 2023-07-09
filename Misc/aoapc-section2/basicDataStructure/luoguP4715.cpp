#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

std::unordered_map<int, int> pos;
std::queue<int> q;

int main () {
	int n, elem;
	std::cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		std::cin >> elem;
		pos[elem] = i + 1;
		q.push(elem);
	}
	while (q.size() != 2) {
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		q.push(std::max(a, b));
	}
	int a = q.front(); q.pop();
	int b = q.front(); q.pop();
	std::cout << pos[std::min(a, b)] << '\n';
}