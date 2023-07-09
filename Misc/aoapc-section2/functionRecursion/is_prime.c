#include <math.h>
#include <stdio.h>
// #define loop for (;;)
// #define mfor (x..y) while (int i = x; i < y; i++)

int isprime(int n) {
    if (n <= 0)
        return 0;
    int m = floor(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main() {}
