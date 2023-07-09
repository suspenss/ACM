struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) {
            return false;
        }
        siz[fb] += siz[fa];
        f[fa] = fb;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};