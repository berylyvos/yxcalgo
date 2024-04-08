#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acwing.com/problem/content/805/

vector<pair<int, int>> interval;
int n, a, b;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        interval.emplace_back(a, b);
    }
    
    // sort by left endpoints
    sort(interval.begin(), interval.end());
    
    int res = 0, tail = -1e9 - 1;
    for (auto& [l, r]: interval) {
        if (l <= tail) tail = max(tail, r);
        else {
            ++res;
            tail = r;
        }
    }

    cout << res;
    
    return 0;
}