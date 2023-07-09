#include <bits/stdc++.h>

using namespace std;
bool isodd(int i) { return i % 2 != 0; }
void print(int * a, int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, o = 0, e = 0, bob = 0, alice = 0;
        cin >> n;
        int a[n], odd[n], even[n];
        for (int i = 0, temp = 0; i < n; i++) {
            cin >> temp;
            if (isodd(temp)) {
                odd[o++] = temp;
            } else {
                even[e++] = temp;
            }
        }
        sort(odd, odd + o);
        sort(even, even + e);
        // e = e - 1, o = o - 1;
        // bool turn = true;
        // while (o >= 0 && e >= 0) {
        //     if (turn) {
        //         alice += even[e--];
        //         turn = false;
        //     } else {
        //         bob += odd[o--];
        //         turn = true;
        //     }
        // }
        int i = n - 1, j = 0;
        for (e = e - 1, o = o - 1; o >= 0 && e >= 0; i--, j++) {
            if (j % 2 != 0)
                a[i] = odd[o--];
            else
                a[i] = even[e--];
        }
        while (o >= 0) {
            a[i--] = odd[o--];
        }
        while (e >= 0) {
            a[i--] = even[e--];
        }
        print(a, n);
        bool turn = true;
        for (int i = n - 1, turn = 1; i >= 0; i--) {
            if (turn && a[i] % 2 == 0) {
                alice += a[i];
            } else if (turn == false && a[i] % 2 != 0) {
                bob += a[i];
            }
            turn = !turn;
        }
        if (bob > alice) {
            cout << "Bob";
        } else if (bob == alice) {
            cout << "Tie";
        } else {
            cout << "Alice";
        }
        cout << "\n";
        cout << "Bob and Alice are here" << bob << " " << alice << endl;
    }
}
