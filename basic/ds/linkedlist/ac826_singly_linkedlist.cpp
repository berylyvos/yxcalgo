#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/828/

const int N = 100010;

int e[N], ne[N], head, idx;

void init() {
    head = -1;
    idx = 0;
}

void addToHead(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

void insert(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int k) {
    if (k == -1) head = ne[head];
    ne[k] = ne[ne[k]];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int n;
    cin >> n;
    while (n--) {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            addToHead(x);
        } else if (op == 'I') {
            cin >> k >> x;
            insert(k - 1, x);
        } else {
            cin >> k;
            remove(k - 1);
        }
    }
    
    for (int i = head; ~i; i = ne[i]) cout << e[i] << ' ';
    return 0;
}