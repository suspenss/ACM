#include <iostream>
#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>
// f[i][j] = max(f[i][j], f[i][j - v] + w)
const int maxn = 1000 + 10;
std::unordered_map<int, std::vector<std::pair<int, int>>> hash;
int f[maxn];

int main() {
    int V, N;
    std::cin >> V >> N;
    for (int i = 1, v, w, c; i <= N; i++) {
        std::cin >> v >> w >> c;
        hash[c].push_back(std::make_pair(v, w));
    }
    std::vector<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i);
    std::ranges::sort(a);
    for (auto [_, things] : hash)
        for (int j = V; j >= 1; j--)
            for (auto thing : things)
                if (j >= thing.first)
                    f[j] = std::max(f[j], f[j - thing.first] + thing.second);

    std::cout << f[V] << '\n';
}