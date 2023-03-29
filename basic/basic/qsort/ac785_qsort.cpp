#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], n;

void qsort(int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        while (a[--j] > x);
        while (a[++i] < x);
        if (i < j) swap(a[i], a[j]);
    }

    qsort(l, j);
    qsort(j + 1, r);
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    qsort(0, n - 1);

    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    return 0;
}