#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if ((a == 1 && n % b == 1) || (b == 1)) {
            cout << "Yes";
        } else if (a == 1 && n % b != 1) {
            cout << "No";
        } else {
            bool found = false;
            for (int i = 1; i <= n; i *= a) {
                if ((n - i) % b == 0) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "Yes";
            } else {
                cout << "No";
            }
        }
        cout << "\n";
    }
}
