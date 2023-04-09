#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/837/

const int N = 100010;
int son[N][26], cnt[N];
int idx, m;

void insert(const string& x) {
    int p = 0;
    for (int i = 0, n = x.size(); i < n; ++i) {
        int &s = son[p][x[i] - 'a'];
        if (!s) s = ++idx;
        p = s;
    }
    cnt[p]++;
}

int query(const string& x) {
    int p = 0;
    for (int i = 0, n = x.size(); i < n; ++i) {
        int s = son[p][x[i] - 'a'];
        if (!s) return 0;
        p = s;
    }
    return cnt[p];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m;
    
    char op;
    string x;
    while (m--) {
        cin >> op >> x;
        if (op == 'I') insert(x);
        else cout << query(x) << '\n';
    }
    
    return 0;
}