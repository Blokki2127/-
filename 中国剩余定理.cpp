/// 中国剩余定理
/// 模板 1 实现简单，只适用于互质的情况，时间复杂度 O(∏m) 一般弃用
/// 模板 2 适应不互质的情况，时间复杂度 O(nlog(max(m)))
#include <bits/stdc++.h>
using namespace std;

/*
 *  模板 1 开始
 */

long long chinese_remainde_theorem1(vector<pair<long long, long long>> v) {
    long long ans = 1, add = 1;
    for (auto p : v) {
        while (ans % p.first != p.second) ans += add;
        add *= p.first;
    }
    return ans;
}

/*
 *  模板 1 结束
 */

/*
 *  模板 2 开始
 *  适应不互质的情况
 */

long long ex_gcd(long long a, long long b, long long &x, long long &y) {    //扩展欧几里得算法
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long gcd = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

// 无解将返回 -1
long long chinese_remainde_theorem2(vector<pair<long long, long long>> v) {
    long long r1 = v[0].second, m1 = v[0].first, r2, m2;
    for (int i = 1; i < v.size(); i++) {
        r2 = v[i].second, m2 = v[i].first;
        long long x, y, g = ex_gcd(m1, m2, x, y), t = m2 / g;
        if ((r2 - r1) % g) return -1;
        r1 += (r2 - r1) / g % t * (x % t) % t * m1;
        m1 = m1 * m2 / g;
        r1 = r1 % m1 + (r1 < 0 ? m1 : 0);
    }
    return r1;
}

/*
 *  模板 2 结束
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for(int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    cout << chinese_remainde_theorem2(v);
    return 0;
}