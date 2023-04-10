#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/839/

const int N = 100010;
int p[N], cnt[N], n, m;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        p[a] = b;
        cnt[b] += cnt[a];
    }
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) p[i] = i, cnt[i] = 1;
    char op[2];
    int a, b;
    while (m--) {
        cin >> op;
        if (*op == 'C') {
            cin >> a >> b;
            merge(a, b);
        } else if (op[1] == '1') {
            cin >> a >> b;
            cout << ((a == b || find(a) == find(b)) ? "Yes\n" : "No\n");
        } else {
            cin >> a;
            cout << cnt[find(a)] << '\n';
        }
    }
    
    return 0;
}