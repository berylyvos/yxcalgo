#include <iostream>
#include <queue>
using namespace std;

// https://www.acwing.com/problem/content/description/150/
// Huffman tree

int n, x;

int main() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q.push(x);
    }
    
    int res = 0;
    while (q.size() > 1) {
        int t = q.top(); q.pop();
        t += q.top(); q.pop();
        res += t;
        q.push(t);
    }
    
    cout << res;
    return 0;
}