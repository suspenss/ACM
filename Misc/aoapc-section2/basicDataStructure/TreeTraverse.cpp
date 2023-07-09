#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int maxn = 40;
int post_order[maxn], in_order[maxn], pos[maxn];
int lch[maxn], rch[maxn];
int n;

int build(int pl, int pr, int il, int ir) {
	int root = post_order[pr], k = pos[root];
	if (il < k) lch[root] = build(pl, pl + k - 1 - il, il, k - 1);
	if (k < ir) rch[root] = build(pl + k - il, pr - 1, k + 1, ir);
	return root;
}

void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		cout << u << ' ';
		if (lch[u]) q.push(lch[u]);
		if (rch[u]) q.push(rch[u]);
	}
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> post_order[i];
	for (int i = 0; i < n; i++) {
		cin >> in_order[i];
		pos[in_order[i]] = i;
	}
	int root = build(0, n - 1, 0, n - 1);
	bfs(root);
	return 0;
}