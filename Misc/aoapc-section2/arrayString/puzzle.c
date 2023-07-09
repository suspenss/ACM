#include <stdio.h>

int main() {
    char g[5][7];
    while (fgets(g[0], 6, stdin) && g[0][0] != 'Z') {
        for (int i = 1; i < 5; i++)
            fgets(g[i], 7, stdin);
    }
}
