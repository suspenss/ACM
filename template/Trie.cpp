struct Trie {
    constexpr static int N = 1e6;

    int cnt;
    std::vector<std::vector<int>> next;
    std::vector<bool> exist;

    Trie(int elem, int n = N) {
        cnt = 0;
        next.assign(N, std::vector<int>(elem));
        exist.assign(N, false);
    }

    void insert(std::string &s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (next[p][c] == 0) next[p][c] = ++cnt;
            p = next[p][c];
        }
        exist[p] = true;
    }

    bool find(std::string &s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (next[p][c] == 0) return false;
            p = next[p][c];
        }
        return exist[p];
    }
};