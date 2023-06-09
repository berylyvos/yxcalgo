#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/829/

const int N = 100010;

int e[N], l[N], r[N], idx;

void init() {
    r[0] = 1, l[1] = 0, idx = 2;
}

void insert(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k], l[r[k]] = idx, r[k] = idx++;
}

void remove(int k) {
    r[l[k]] = r[k], l[r[k]] = l[k];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int n, x, k;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "L") { 
            cin >> x;
            insert(0, x);
        } else if (op == "R") {
            cin >> x;
            insert(l[1], x);
        } else if (op == "D") {
            cin >> k;
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            insert(l[k + 1], x);
        } else { 
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    
    return 0;
}