#include <iostream>

int n, cnt = 0, vis[8], row[30], k1[30], k2[30];
void dfs(int step) {
    if (step > n) {
        if (cnt < 3) {
            for (int i = 1; i <= n; i++)
                std::cout << vis[i] << ' ';
            std::cout << '\n';
        }
        cnt++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (row[i] || k1[step + i] || k2[step - i + n])
            continue;
        vis[step] = i;
        row[i] = 1, k1[step + i] = 1, k2[step - i + n] = 1;
        dfs(step + 1);
        row[i] = 0, k1[step + i] = 0, k2[step - i + n] = 0;
    }
}

int main() {
    std::cin >> n;
    dfs(1);
    std::cout << cnt;

}
