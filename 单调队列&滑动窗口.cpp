/// 单调队列/滑动窗口
/// 用于获得滑动窗口内的最值
/// 可以通过存储下标来优化常数时间，但是需要写进 main
#include<bits/stdc++.h>
using namespace std;

/*
 *  模板开始
 */

struct queue_min {
    deque<int> q;

    void push(int x) {
        while (!q.empty() && x < q.back()) q.pop_back();
        q.push_back(x);
    }

    void pop(int x) {if (x == q.front()) q.pop_front();}

    int get_min() {return q.front();}
};

struct queue_max {
    deque<int> q;

    void push(int x) {
        while (!q.empty() && x > q.back()) q.pop_back();
        q.push_back(x);
    }

    void pop(int x) {if (x == q.front()) q.pop_front();}

    int get_max() {return q.front();}
};

/*
 *  模板结束
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int min[n - k + 1], max[n - k + 1];
    queue_min q_min;
    queue_max q_max;
    queue<int> q;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        q_min.push(x);
        q_max.push(x);
        q.push(x);
    }
    for(int i = k; i < n; i++) {
        min[i - k] = q_min.get_min();
        max[i - k] = q_max.get_max();
        int x;
        cin >> x;
        q_min.push(x);
        q_max.push(x);
        q.push(x);
        q_min.pop(q.front());
        q_max.pop(q.front());
        q.pop();
    }
    min[n - k] = q_min.get_min();
    max[n - k] = q_max.get_max();
    for (int i : min) cout << i << " ";
    cout << endl;
    for (int i : max) cout << i << " ";
    return 0;
}