#include <stdio.h>

double a, b, c, d;
double f(double x) { return a * x * x * x + b * x * x + c * x + d; }

int main() {
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    int l = -100, r = 100, cnt = 0;
    for (int i = -100; i < 100 && cnt < 4; i++) {
        double l = i * 1.0, r = i + 1.0;
        if (f(l) == 0) {
            printf("%.2lf ", l);
            cnt++;
        }
        if (f(i) * f(i + 1) < 0) {
            while (r - l >= 0.001) {
                double mid = 1.0 * (l + r) / 2;
                if (f(l) * f(mid) <= 0) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            printf("%.2lf ", l);
            cnt++;
        }
    }
}
