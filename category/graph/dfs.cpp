#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
typedef long long i64;

int f[10];
// graphy's storage
const int maxn = 1e5 + 10, maxm = maxn * 2;
int h[maxn], e[maxm], ne[maxm], idx, ans = maxn, n;
bool st[maxn];


int dfs(int u) {
    // 计算一个树的所有儿子节点个数 = 1（这个节点本身）+ 各个子树的儿子节点个数 （递归定义）
    int sum = 1, res = 0;
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int t = dfs(j);
            res = std::max(res, t); // res 为所有子树的节点和的最大值
            sum += t;
        }
    }
    res = std::max(res, n - sum); // res 目前为所有子树的节点和的最大值，需要和当前节点上面的连通块的大小比较取最大值
    ans = std::min(ans, res); // 取每个节点的res的最小值

    return sum;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


void process () {

}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    // std::cin >> T;

    while (T--) {
        process();
    }
}