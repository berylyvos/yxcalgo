#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/submission/802/

const int N = 100010;
int a[N], b[N], n, m, x;

int main() {
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    
    for (int i = 0, j = m - 1;;) {
        int s = a[i] + b[j];
        if (s > x) {
            --j;
        } else if (s < x) {
            ++i;
        } else {
            printf("%d %d", i, j);
            break;
        }
    }
    
    return 0;
}