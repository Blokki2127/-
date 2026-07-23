/// 快速幂板子
/// 求 a 的 b 次幂模 p
/// (a ^ b) mod p
#include<bits/stdc++.h>
using namespace std;

/*
 *  模板开始
 */

long long fast_exponentiation(long long a, long long b, long long p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}

/*
 *  模板结束
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, p;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << fast_exponentiation(a, b, p) << endl;
    return 0;
}