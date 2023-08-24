#include <iostream>
#include <vector>
#include <cmath>

typedef long long i64;

i64 k, inf;

bool check(i64 x) {
    i64 sum = 0, layer = k;
    i64 all = (1 + layer) * layer - k;
    if (x <= layer) sum = (1 + x) * x / 2;
    else sum = all - (2 * layer - x) * (2 * layer - x - 1) / 2;
    return sum >= inf;
}


void sol() {
    std::cin >> k >> inf;
    i64 l = 0, r = 2 * k;
    while (l + 1 != r) {
        i64 mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (r == 2 * k) std::cout << l << "\n";
    else std::cout << r << "\n";
}



int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) {
        sol();
    }
    return 0;
}