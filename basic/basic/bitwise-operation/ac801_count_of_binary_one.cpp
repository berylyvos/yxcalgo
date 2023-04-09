#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/803/

int n, x;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        int cnt = 0;
        while (x) {
            // x -= (x & (-x));
            x &= (x - 1);
            ++cnt;
        }
        cout << cnt << ' ';
    }
    
    return 0;
}