#include <bits/stdc++.h>

using namespace std;
string cs = "codeforces";

long long product(int * a, int len);
void initlist(int * a, int head, int last, int value);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[10], cnt = 1;
    long long k;
    initlist(a, 0, 9, 1);
    cin >> k;
    if (k == 1) {
        cout << cs << endl;
        return 0;
    }
    while (pow(cnt, 10) < k) {
        cnt++;
    }
    while (product(a, 9) < k) {
        for (int i = 0; i < 10; i++) {
            if (a[i] < cnt) {
                a[i] += 1;
            }
            if (product(a, 9) >= k) {
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        // cout << a[i];
        for (int j = 0; j < a[i]; j++) {
            cout << cs[i];
        }
    }
}
long long product(int * a, int len) {
    long long pro = 1;
    for (int i = 0; i <= len; i++) {
        pro *= a[i];
    }
    return pro;
}
void initlist(int * a, int head, int last, int value) {
    for (int i = head; i <= last; i++) {
        a[i] = value;
    }
}
