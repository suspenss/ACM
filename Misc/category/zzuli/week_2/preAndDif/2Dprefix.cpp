#include <iostream>
using namespace std;

// int query(int * prefixSum, int x1, int y1, int x2, int y2);
int main() {
    int partion[3][4] = {
        {1, 5, 6, 8},
        {9, 6, 7, 3},
        {5, 3, 2, 4},
    };

    int sum[4][5] = {0}; // initalize prefix martix to 0
    sum[1][1] = partion[0][0];
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 5; j++)
            sum[i][j] = partion[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] -
                        sum[i - 1][j - 1];
    // cout << query(*sum, 1, 1, 2, 2);
    int query, x1 = 2, y1 = 2, x2 = 3, y2 = 3;
    query =
        sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    cout << query << endl;
}

// int query(int * prefixSum, int x1, int y1, int x2, int y2{
// return prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1]
// +
//        prefixSum[x1 - 1][y1 - 1];
// }
// for (int i = 0; i < 4; i++) {
//     for (int j = 0; j < 5; j++) {
//         cout << sum[i][j] << " ";
//     }
//     cout << endl;
// }
