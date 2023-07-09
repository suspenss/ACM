#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

struct Node {
	bool have_value;
	int v;
	Node * left, * right;
	Node() : have_value(false), left(nullptr), right(nullptr) {}
};
Node * root = nullptr;
bool failed = false;

Node * newNode () {return new Node();};

void addNode(int v, std::string_view s) {
	Node * u = root;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') {
			if (u->left == nullptr)  u->left = newNode();
			u = u->left;
		} else if (s[i] == 'R') {
			if (u->right == nullptr) u->right = newNode();
			u = u->right;
		}
	}
	if (u->have_value) failed = true;
	u->v = v;
	u->have_value = true;
}

bool bfs(std::vector<int> & ans) {
	std::queue<Node *> q;
	q.push(root);
	ans.clear();
	while (!q.empty()) {
		Node * u = q.front(); q.pop();
		if (u->have_value == false) return false;
		ans.push_back(u->v);
		if (u->left) q.push(u->left);
		if (u->right) q.push(u->right);
	}
	return true;
}

void removeTree(Node * u) {
	if (u == nullptr) return;
	removeTree(u->left);
	removeTree(u->right);
	delete u;
}

void process () {
	std::string node;
	root = newNode();
	while (std::cin >> node) {
		if (node.size() == 2) {
			std::vector<int> ans;
			if (bfs(ans)) {
				for (auto i : ans) std::cout << i << " ";
				std::cout << '\n';
			} else std::cout << "not complete\n";
			removeTree(root);
			root = newNode();
			continue;
		}
		int i = node.find(','), v = stoi(node.substr(1, i - 1));
		addNode(v, node.substr(i + 1, node.size() - i - 2));
	}
}

int main () {
	process();
	return 0;
}

