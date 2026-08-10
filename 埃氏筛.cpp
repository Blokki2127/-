/// 埃氏筛板子
/// 1. 初始化筛
/// 2. 在范围内判断是否是质数
#include <bits/stdc++.h>
using namespace std;

struct e_sieve {
    vector<char> sieve;
    vector<long long> prime;

    e_sieve(long long N) {
        sieve = vector<char>(N + 1, true);
        if (N < 2) return;
        prime.push_back(2);
        if (N == 2) return;
        for (long long i = 3; i <= N; i += 2) {
            if (sieve[i]) {
                prime.push_back(i);
                for (long long j = i * i; j <= N; j += 2 * i) sieve[j] = false;
            }
        }
    }

    bool isPrime(long long i) {
        if (prime.empty()) return false;
        long long l = 0, r = (long long)prime.size() - 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (prime[mid] == i) return true;
            if (prime[mid] > i) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    e_sieve e(n);
    while (q--) {
        int k;
        cin >> k;
        cout << e.prime[k - 1] << '\n';
    }
}