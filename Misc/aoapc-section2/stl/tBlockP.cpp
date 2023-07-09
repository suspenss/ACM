#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
vector<int> pile[maxn];
int n;

void print() {
    for (int i = 0; i < n; i++) {
        cout <<  i << ":";
        for (int j = 0; j < pile[i].size(); j++)
            cout << " " << pile[i][j];
        cout << "\n";
    }
}
void find_block(int a, int &p, int &h) {
    for (p = 0; p < n; p++)
        for (h = 0; h < pile[p].size(); h++)
            if (a == pile[p][h]) return;
}

void recover(int p, int h) {
    for (int i = h + 1; i < pile[p].size(); i++) {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}

void pile_onto(int pa, int ha, int pb) {
    for (int i = ha ; i < pile[pa].size(); i++)
        pile[pb].push_back(pile[pa][i]);
    pile[pa].resize(ha);
}

int main () {
    cin >> n;
    int l1, l2;
    string o, d;
    for (int i = 0; i < n; i++) pile[i].push_back(i);
    while (cin >> o && o != "quit") {
        cin >> l1 >> d >> l2;
        int pa, ha, pb, hb;
        find_block(l1, pa, ha);
        find_block(l2, pb, hb);
        if (pa == pb) continue;
        if (o == "move") recover(pa, ha);
        if (d == "onto") recover(pb, hb);
        pile_onto(pa, ha, pb);
    }
    print();
    return 0;
}