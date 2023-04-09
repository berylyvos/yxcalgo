#include <iostream>
#include <unordered_map>
using namespace std;
// https://www.acwing.com/problem/content/801/

const int N = 100010;
int a[N], n;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int res = 0;
    unordered_map<int, int> cnt;
    for (int i = 0, j = 0; j < n; ++j) {
        ++cnt[a[j]];
        while (cnt[a[j]] > 1) --cnt[a[i++]];
        res = max(res, j - i + 1);
    }
    
    cout << res;
        
    return 0;
}