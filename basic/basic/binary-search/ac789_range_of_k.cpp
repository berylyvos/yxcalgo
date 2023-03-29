#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/791/

const int N = 100010;
int a[N];
int n, q, k;

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    while (q--) {
        scanf("%d", &k);
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        int left = r;
        if (a[r] != k) printf("-1 -1\n");
        else {
            r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (a[mid] <= k) l = mid;
                else r = mid - 1;
            }
            printf("%d %d\n", left, r);
        }
        
    }
    return 0;
}