template<class T>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> st;

    using optFunction = std::function<T(const T &, const T &)>;
    optFunction opt;
    static T defaultOpt(const T &a, const T &b) {
        return std::max(a, b);
    }

    SparseTable(const std::vector<T> &_init, optFunction _opt = defaultOpt) {
        opt = _opt;
        init(_init);
    }

    SparseTable(const std::ranges::iota_view<int, int> _init, optFunction _opt = defaultOpt) {
        opt = _opt;
        init(_init);
    }

    void init(auto &_init) {
        n = _init.size();
        int cap = std::log2(n) + 1;
        st.assign(n, std::vector<T>(cap));

        for (int i = 0; i < n; i++) {
            st[i][0] = _init[i];
        }

        for (int j = 1; j < cap; j++) {
            int cur = 1 << (j - 1);
            for (int i = 0; i + cur < n; i++) {
                st[i][j] = opt(st[i][j - 1], st[i + cur][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int k = std::log2(r - l + 1);
        return opt(st[l][k], st[r - (1 << k) + 1][k]);
    }

    T query(int l, int r, int k) {
        return opt(st[l][k], st[r - (1 << k) + 1][k]);
    }
};