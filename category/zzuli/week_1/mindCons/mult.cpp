#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    LL a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "1 1\n" << -a[0] << endl;
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n";
    } else {
        cout << "1 " << n << "\n0 ";
        for (int i = 1; i < n; i++) {
            cout << n * -a[i] << " ";
        }
        cout << "\n2 " << n << "\n";
        for (int i = 1; i < n; i++) {
            cout << a[i] * (n - 1) << " ";
        }
    }
}
