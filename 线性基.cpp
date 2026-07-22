/// 线性基板子
/// 1. 最大异或和
/// 2. 检查能否通过异或获得目标值
#include <bits/stdc++.h>
using namespace std;

#define bits_of_type 63                 // int 需要改成31

typedef struct linear_basis {
    long long v[bits_of_type] = {};     // 也可以是 int

    bool add(long long a) {
        for (int i = bits_of_type - 1; i >= 0; i--) {
            if (a >> i & 1) {
                if (v[i]) a ^= v[i];
                else {
                    v[i] = a;
                    return true;
                }
            }
            else if (a == 0) return false;
        }
        return false;
    }

    bool check(long long a) {
        for (int i = bits_of_type - 1; i >= 0; i--) {
            if (a >> i & 1) {
                if (!v[i]) return false;
            }
        }
        return true;
    }

    long long max() {
        long long max = 0;
        for (int i = bits_of_type - 1; i >= 0; i--) {
            if (v[i]) max = max > (max ^ v[i]) ? max : max ^ v[i];
        }
        return max;
    }
} linear_basis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long a[n];
    linear_basis lb;
    for (long long &i : a) {
        cin >> i;
        lb.add(i);
    }
    cout << lb.max() << endl;

    return 0;
}