/// 线性基板子
/// 1. 最大异或和
/// 2. 检查能否通过异或获得目标值
#include <bits/stdc++.h>
using namespace std;

/*
 *  模板开始
 */

#define bits_of_type 63                 // int 需要改成31

typedef struct linear_basis {
    long long base[bits_of_type] = {};     // 也可以是 int

    bool add(long long a) {
        for (int i = bits_of_type - 1; i >= 0; i--) {
            if (a >> i & 1) {
                if (base[i]) a ^= base[i];
                else {
                    base[i] = a;
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
                if (!base[i]) return false;
                a ^= base[i];
            }
        }
        return true;
    }

    long long max() {
        long long max = 0;
        for (int i = bits_of_type - 1; i >= 0; i--) {
            if (base[i]) max = max > (max ^ base[i]) ? max : max ^ base[i];
        }
        return max;
    }
} linear_basis;

/*
 *  模板结束
 */

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