/// 队列
/// 1. 数组模拟实现
/// 2. 双栈模拟实现
#include<bits/stdc++.h>
using namespace std;

/*
 *  模板 1 开始
 */

#define MAX_NUM 1000000

typedef struct queue1 {
    int a[MAX_NUM], size_of_queue = 0, front = 0;

    void push(int x) {
        a[(front + size_of_queue) % MAX_NUM] = x;
        size_of_queue++;
    }

    void pop() {
        size_of_queue--;
        front = (front + 1) % MAX_NUM;
    }

    int query() {
        return a[front];
    }

    int size() {
        return size_of_queue;
    }
} queue1;

/*
 *  模板 1 结束
 */

/*
 *  模板 2 开始
 */

typedef struct queue2 {
    stack<int> s1, s2;

    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int query() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size() {
        return s1.size() + s2.size();
    }
} queue2;

/*
 *  模板 2 结束
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    queue1 q;
    for (int i = 0; i < n; i++) {
        int op, x;
        cin >> op;
        switch (op) {
            case 1:
                cin >> x;
                q.push(x);
                break;
            case 2:
                if (q.size()) q.pop();
                else cout << "ERR_CANNOT_POP" << endl;
                break;
            case 3:
                if (q.size()) cout << q.query() << endl;
                else cout << "ERR_CANNOT_QUERY" << endl;
                break;
            case 4:
                cout << q.size() << endl;
                break;
        }
    }
}