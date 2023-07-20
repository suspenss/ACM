struct Disjoint_Set {
    std::vector<int> f, _size, _depth;

    Disjoint_Set() {}
    Disjoint_Set(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        _depth.assign(n, 0);
        _size.assign(n, 1);
    }

    int find(int x) {
        if (f[x] == x) return x;

        int theory_father = f[x];
        f[x] = find(f[x]);
        _depth[x] += _depth[theory_father];
        return f[x];
    }

    bool merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return false;

        f[fu] = fv;
        _depth[fu] = _size[fv];
        _size[fv] += _size[fu];
        return true;
    }

    int depth(int x) {
        return _depth[x];
    }

    int distance(int u, int v) {
        if (same(u, v) == false) return -1;
        return std::abs(depth(u) - depth(v)) - 1;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int size(int x) {
        return _size[find(x)];
    }
};