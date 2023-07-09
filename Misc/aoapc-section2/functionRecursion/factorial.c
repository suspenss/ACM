#include <stdio.h>

long long factorial(int n) {
    // recursion
    // 3 calculate operator
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main() {
    printf("%lld", factorial(5));
    return 0;
}
