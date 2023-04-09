#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/description/790/

using ll = long long;
const int N = 100010;
int a[N], t[N], n;

ll merge_and_count(int l, int r) {
    if (l >= r) return 0;
    
    int mid = (l + r) >> 1;
    ll cnt = merge_and_count(l, mid) + merge_and_count(mid + 1, r);
    
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) t[k++] = a[i++];
        else {
            t[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    
    i = l, j = 0;
    while (j < k) a[i++] = t[j++];
    
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    cout << merge_and_count(0, n - 1);
    
    return 0;
}