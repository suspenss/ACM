#include <iostream>
using namespace std;

int map[5005][5005];

int main() {
    int n, m, x, y, v, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> v;
        map[x + 1][y + 1] += v;
    }
    for (int i = 1; i < 5002; i++)
        for (int j = 1; j < 5002; j++)
            map[i][j] =
                map[i][j] + map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
    for (int i = m; i < 5002; i++)
        for (int j = m; j < 5002; j++) {
            ans = max(ans, map[i][j] + map[i - m][j - m] - map[i - m][j] -
                               map[i][j - m]);
        }
    cout << ans << endl;
}
