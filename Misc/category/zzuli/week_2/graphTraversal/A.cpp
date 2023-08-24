#include <bits/stdc++.h>
using namespace std;

int vis[100010];
vector<vector<int>> graph;

void dfs(int inside, int outside) {
    if (vis[inside])
        return;
    vis[inside] = outside;
    for (int i = 0; i < graph[inside].size(); i++)
        dfs(graph[inside][i], outside);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[v].push_back(u);
    }
    for (int i = n; i > 0; i--)
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << endl;
}
