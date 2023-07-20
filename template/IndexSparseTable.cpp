template<class T>
struct SparseTable {
    int n, layer;
    std::vector<T> value;
    std::vector<std::vector<T>> st;

    using optFunction = std::function<T(const T &, const T &)>;
    optFunction opt;
    static T defaultOpt(const T &a, const T &b) {
        return std::max(a, b);
    }

    SparseTable(int N, optFunction _opt = defaultOpt) {
        opt = _opt;
        init(N);
    }

    void init(int N) {
        n = N;
        layer = std::log2(n) + 1;
        st.assign(n, std::vector<T>(layer));
        value.assign(n, 0);
    }

    void build() {
        for (int i = 0; i < n; i++) {
            st[i][0] = i;
        }

        for (int j = 1; j < layer; j++) {
            int cur = 1 << (j - 1);
            for (int i = 0; i + cur < n; i++) {
                int l = st[i][j - 1];
                int r = st[i + cur][j - 1];
                if (opt(value[l], value[r]) == value[l]) {
                    st[i][j] = l;
                } else {
                    st[i][j] = r;
                }
            }
        }
    }

    int indexQuery(int l, int r) {
        int k = std::log2(r - l + 1);
        int left = st[l][k];
        int right = st[r - (1 << k) + 1][k];

        if (opt(value[left], value[right]) == value[left]) {
            return left;
        } else {
            return right;
        }
    }

    T query(int l, int r) {
        return value[indexQuery(l, r)];
    }

    T &operator[](const int &index) {
        return value[index];
    }
};