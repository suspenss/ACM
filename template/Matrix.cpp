using i64 = int64_t;
constexpr i64 MOD = 1e9;
struct Matrix {
    int row, column;
    std::vector<std::vector<int>> data;

    Matrix() {}
    Matrix(int n, int m) {
        init(n, m);
    }

    void init(int n, int m) {
        row = n, column = m;
        data.assign(n, std::vector<int>(m));
    }

    std::vector<int> operator[](const int &x) {
        return data[x];
    }

    Matrix operator*(const Matrix &other) const {
        Matrix res(row, other.column);
        int r = row, c = other.column, l = column;

        for (int i = 0; i < r; i++) {
            for (int k = 0; k < l; k++) {
                int cur = data[i][k];
                for (int j = 0; j < c; j++) {
                    res[i][j] += cur * other.data[k][j];
                    res[i][j] %= MOD;
                }
            }
        }

        return res;
    }
};
