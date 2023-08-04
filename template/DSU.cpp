struct DisjointSet {
    std::vector<int> f, _size;

    DisjointSet() {}
    DisjointSet(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        _size.assign(n, 1);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return false;

        f[fu] = fv;
        _size[fv] += _size[fu];
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int size(int x) {
        return _size[find(x)];
    }
};