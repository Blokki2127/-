/// 扩展欧几里得算法
/// 在欧几里得算法返回最大公因数的基础上 返回 a * x + b * y = gcd 的一组解
#include <bits/stdc++.h>
using namespace std;

long long ex_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long gcd = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b, x, y;
    cin >> a >> b;
    cout << ex_gcd(a, b, x, y)  << ' ' << x << ' ' << y << endl;
}