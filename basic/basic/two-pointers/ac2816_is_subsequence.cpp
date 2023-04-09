#include <iostream>
using namespace std;
// https://www.acwing.com/problem/content/description/2818/

const int N = 100010;
int a[N], b[N], n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    int i = 0;
    for (int j = 0; j < m; ++j)
        if (a[i] == b[j])
            if (++i == n) {
                cout << "Yes";
                return 0;
            }
        
    cout << "No";
    return 0;
}