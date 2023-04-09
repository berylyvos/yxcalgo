#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N], t[N], n;

void merge_sort(int l, int r) {
    if (l >= r) return;
    
    int mid = (l + r) >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) 
        t[k++] = a[i] <= a[j] ? a[i++] : a[j++];
        
    while (i <= mid) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    
    i = l, j = 0;
    while (j < k) a[i++] = t[j++];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    merge_sort(0, n - 1);
    
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    return 0;
}