#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/803/

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        int cnt = 0;
        while (x) {
            // x -= (x & (-x));
            x &= (x - 1);
            ++cnt;
        }
        printf("%d ", cnt);
    }
    return 0;
}