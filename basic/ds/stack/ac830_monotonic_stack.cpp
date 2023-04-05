#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/description/832/

const int N = 100010;
int st[N], tt, n, x;

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        // 维护st严格单调递增
        while (tt && st[tt] >= x) --tt;
        if (tt) printf("%d ", st[tt]);
        else printf("-1 ");
        st[++tt] = x;
    }
    
    return 0;
}