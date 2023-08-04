template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;

    SegmentTree() : n(0) {}
    SegmentTree(int n, Info _info = Info()) {
        init(std::vector<Info>(n, _info));
    }

    template<class T>
    SegmentTree(std::vector<T> _init) {
        init(_init);
    }
    template<class T>
    void init(std::vector<T> _init) {
        n = _init.size();
        info.assign(4 << std::__lg(n), Info());

        auto build = [&_init, this](auto self, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = Info(_init[l]);
                return;
            }

            int mid = (l + r) / 2;
            self(self, p * 2, l, mid);
            self(self, p * 2 + 1, mid, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }

    void pull(int p) {
        info[p] = info[p * 2] + info[p * 2 + 1];
    }

    void update(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }

        int mid = (l + r) / 2;
        if (x < mid) {
            update(p * 2, l, mid, x, v);
        } else {
            update(p * 2 + 1, mid, r, x, v);
        }
        pull(p);
    }
    void update(int x, const Info &v) {
        update(1, 0, n, x, v);
    }

    Info rangeQuery(int p, int s, int e, int l, int r) {
        if (s >= r or e <= l) {
            return Info();
        }

        if (s >= l and e <= r) {
            return info[p];
        }

        int mid = (s + e) / 2;
        return rangeQuery(p * 2, s, mid, l, r) + rangeQuery(p * 2 + 1, mid, e, l, r);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};