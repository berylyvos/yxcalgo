#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/description/788/

const int N = 1e5 + 10;
int a[N], n, k;

int qselect(int l, int r) {
    if (l >= r) return a[k];

    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        while (a[--j] > x);
        while (a[++i] < x);
        if (i < j) swap(a[i], a[j]);
    }
    
    if (k <= j) return qselect(l, j);
    return qselect(j + 1, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    --k;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    cout << qselect(0, n - 1);
    return 0;
}