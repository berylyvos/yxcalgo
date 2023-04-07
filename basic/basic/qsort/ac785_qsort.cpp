#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
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
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i < n; ++i) cin >> a[i];

    qsort(0, n - 1);

    for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
    return 0;
}