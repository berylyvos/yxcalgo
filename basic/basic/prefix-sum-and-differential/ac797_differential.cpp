#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/description/799/

const int N = 100010;
int b[N], n, m, l, r, c;

void insert(int l, int r) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c);
        insert(i, i);
    }
    
    while (m--) {
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r);
    }
    
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
        printf("%d ", b[i]);
    }
    
    return 0;
}