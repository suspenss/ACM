// https://vjudge.net/contest/552091#problem/A
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
typedef long long i64;

std::vector<int> fa(30);

// 路径压缩的查询操作
int find(int x) {
    // 如果查询元素的父节点不是它本身, 则递归地查询它的父节点以至于找到祖宗节点, 并将它的父节点指向祖宗节点
    if (fa[x] != x) fa[x] = find(fa[x]);
    // 当查询元素的父节点等于元素本身, 即这个元素就是这个集合的祖宗节点, 就反回它
    return fa[x];
}

void sol() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::iota(fa.begin(), fa.end(), 0); // 初始化父节点数组
    std::vector<int> vis(30); // 初始化vis数组为零, 用来记录某个字母是否以构成环了
    std::map<char, char> ans; // 用来记录给出的字符串的某个字符的环上的上一个值 ( 映射 )

    for (auto c : s) {
        if (ans.count(c)) continue; // 重复元素不用再进行处理
        int idc = find(c - 'a'); // 查询元素的集合

        for (int i = 0; i < 26; i++) {
            int idi = find(i); // 查询匹配元素的集合
            if (vis[i] == 0 && idc != idi) { // 如果这个字母没有被使用过, 且不合待匹配元素在一个集合中
                fa[idi] = idc, ans[c] = i + 'a'; // 匹配字母指向待匹配字母的集合, 并建立映射
                vis[i] = 1; // 标记匹配字母已被使用
                break;
            } else if (vis[i] == 0 && ans.size() == 25) {
                // 特殊情况: 26 个不相同的字母, 则最后一个一定是
                // 和待匹配的字母在同一集合的, 那么按照上面的方法将会取消匹配
                ans[c] = i + 'a';
            }
        }
    }
    for (auto c : s)
        std::cout << ans[c];
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T--) {
        sol();
    }

    return 0;
}