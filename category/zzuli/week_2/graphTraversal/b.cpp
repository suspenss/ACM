#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int vis[100010], vi = 0, bvis[100010];
queue<int> q;
void dfs(int step) {
    cout << step << " ";
    // ans[vi++] = step;
    vis[step] = 1;
    for (int i = 0; i < graph[step].size(); i++) {
        if (vis[graph[step][i]])
            continue;
        dfs(graph[step][i]);
    }
}

void bfs(int u) {
    q.push(u);
    bvis[u] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
        // bans[bi++] = now;
        for (int i = 0; i < graph[now].size(); i++) {
            if (bvis[graph[now][i]])
                continue;
            bvis[graph[now][i]] = 1;
            q.push(graph[now][i]);
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(1);
    cout << endl;
    bfs(1);
    // for (int i = 0; i < n; i++) {
    //     cout << ans[i] << " ";
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << bans[i] << " ";
    // }
}
