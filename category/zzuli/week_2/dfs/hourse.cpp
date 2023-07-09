#include <iostream>

int n, m, x, y, chess[410][410], board[410][410], xnow, ynow;
int position[8][2] = {
    {-1, 2}, {1, 2}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1},
};
void printBoard() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << '\n';
    }
}
void bfs(int step, int xtar, int ytar) {
    if (xtar == x && ytar == y) {
        board[xnow][ynow] = step;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (chess[xtar][ytar])
            continue;
        chess[xtar][ytar] = 1;
        if ((xtar + position[i][0] > 0 && xtar + position[i][0] <= n) &&
            (ytar + position[i][1] > 0 && ytar + position[i][1] <= m))
            xtar += position[i][0], ytar += position[i][1];
        else {
            board[xnow][ynow] = -1;
            return;
        }
        bfs(step + 1, xtar, ytar);
        chess[xtar][ytar] = 0;
    }
}

int main() {
    std::cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            xnow = i, ynow = j;
            bfs(1, i, j);
        }
    }
    printBoard();
    return 0;
}
