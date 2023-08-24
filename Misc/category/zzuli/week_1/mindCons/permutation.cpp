#include <bits/stdc++.h>
using namespace std;

bool iseven(int n) { return (n % 2 == 0) ? true : false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0, n = 0;
    cin >> t;

    while (t--) {
        cin >> n;
        if (n > 4) {
            int len = n / 2;
            int even[len], odd[len + 1];

            for (int i = 0, ep = 2, op = 1; i < len; i++, op += 2, ep += 2) {
                even[i] = ep;
                odd[i] = op;
            }
            odd[len] = odd[len - 1] + 2;

            for (int i = 0; i < len; i++) {
                cout << odd[i] << " ";
            }
            if (!iseven(n)) {
                cout << odd[len] << " ";
                cout << even[len - 2] << " " << even[len - 1] << " ";
                for (int i = len - 3; i >= 0; i--) {
                    cout << even[i] << " ";
                }
                cout << "\n";
            } else {
                cout << even[len - 3] << " " << even[len - 1] << " "
                     << even[len - 2] << " ";
                for (int i = len - 4; i >= 0; i--) {
                    cout << even[i] << " ";
                }
                cout << "\n";
            }
        } else if (n == 4) {
            cout << "3 1 4 2\n";
        } else {
            cout << "-1\n";
        }
    }

    // for (int i = 0; i < len; i++) {
    // cout << "even: " << even[i] << endl << "odd: " << odd[i] << endl;
    // }
    // cout << odd[len];
}