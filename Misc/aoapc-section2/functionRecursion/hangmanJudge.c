#include <stdio.h>
#include <string.h>

int main() {
    int n;
    while (scanf("%d", &n) && n != -1) {
        char s1[100], c;
        int word[28] = {0}, lose = 0, win = 0;

        printf("Round %d\n", n);
        getchar();

        while (scanf("%c", &c) && c != '\n')
            word[c - 'a'] = 1;
        for (int i = 0; i < 28; i++)
            if (word[i])
                win++;
        scanf("%s", s1);
        for (int i = 0; i < strlen(s1); i++) {
            if (word[s1[i] - 'a']) {
                word[s1[i] - 'a'] = 0;
                win--;
                if (win == 0) {
                    puts("You win.");
                    break;
                }
            } else if (word[s1[i] - 'a'] == 0) {
                lose++;
                if (lose > 6) {
                    puts("You lose.");
                    break;
                }
            }
        }
        if (win > 0 && lose < 7)
            puts("You chickened out.");
    }
    return 0;
}
