/// 并查集板子
/// 1. 初始化
/// 2. 查找根节点
/// 3. 合并集合
#include <bits/stdc++.h>
using namespace std;

/*
 *  模板开始
 */

struct union_find {
    vector<int> parent;
    vector<int> rank;

    union_find(int N) {         //初始化函数
        parent = vector<int>(N);
        rank = vector(N, 0);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {           //查找 x 的根节点
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {  //合并 x y 的集合
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot) return;
        if (rank[xroot] <= rank[yroot]) {
            parent[xroot] = yroot;
            rank[yroot] += rank[xroot];
        }
        else {
            parent[yroot] = xroot;
            rank[xroot] += rank[yroot];
        }
    }
};

/*
 *  模板结束
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    union_find uf = union_find(n);
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        x--;
        y--;
        if (z == 1) uf.unite(x, y);
        else if (z == 2) {
            if (uf.find(x) == uf.find(y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }

    return 0;
}