#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/898/

const int N = 100010;
int q[N], x, k, n;

int main() {
    cin >> n;
    
    while (n--) {
        cin >> x;
        if (k == 0 || x > q[k - 1]) q[k++] = x;
        else {
            int l = 0, r = k;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (q[mid] >= x) r = mid;
                else l = mid + 1;
            }
            q[r] = x;
        }
    }
    
    cout << k;
    
    return 0;
}