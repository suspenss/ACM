#include <iostream>
using namespace std;

string t, s;
// char t[300005], s[300005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < m && (t[i] == '?' || s[i] == '?' || t[i] == s[i]))
        i++;
    while (j < m && (t[m - 1 - j] == '?' || s[n - 1 - j] == '?' ||
                     s[n - 1 - j] == t[m - 1 - j]))
        j++;
    for (int k = 0; k <= m; k++) {
        if (k <= i && m - k <= j)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
}
