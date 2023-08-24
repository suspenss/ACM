#include <iostream>

int vis[10] = {0}, a[10];

void dfs(int step, int now) {
    if (step < now) {
        for (int i = 1; i <= step; i++)
            std::cout << "    " << a[i];
        std::cout << '\n';
        return;
    }
    for (int i = 1; i <= step; i++) {
        if (vis[i])
            continue;
        a[now] = i;
        vis[i] = 1;
        dfs(step, now + 1);
        vis[i] = 0;
    }
}

int main() {
    int n;
    std::cin >> n;
    dfs(n, 1);
}
