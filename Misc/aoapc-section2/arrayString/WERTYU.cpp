#include <bits/stdc++.h>
using namespace std;

string we = "  \n\n/.,MNBVCXZ';LKJHGFDSA\\][POIUYTREWQ=-0987654321";
int main() {
    char c;
    while (scanf("%c", &c) != EOF) {
        cout << we[we.find(c) + 1];
    }
}