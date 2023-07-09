#include <iostream>

int match(int n) {
    switch (n) {
    case 0:
        return 6;
    case 1:
        return 2;
    case 2:
        return 5;
    case 3:
        return 5;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 3;
    case 8:
        return 7;
    case 9:
        return 6;
    }
}

int main() {
    int n = 0;
    // int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    std::cin >> n;
    n -= 4;

    //
}
