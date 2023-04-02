#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/797/

const int N = 100010;
int a[N], n, m, l, r;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    
    while (m--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    
    return 0;
}