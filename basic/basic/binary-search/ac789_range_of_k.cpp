#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/description/791/

const int N = 100010;
int a[N];
int n, q, k;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (q--) {
        cin >> k;
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        int left = r;
        if (a[r] != k) cout << "-1 -1\n";
        else {
            r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (a[mid] <= k) l = mid;
                else r = mid - 1;
            }
            cout << left << ' ' << r << '\n';
        }
        
    }
    return 0;
}