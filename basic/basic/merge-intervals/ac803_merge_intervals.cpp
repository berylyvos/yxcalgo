#include <cstdio>
#include <vector>
#include <algorithm>
// https://www.acwing.com/problem/content/description/805/

using namespace std;
using vpii = vector<pair<int, int>>;

vpii interval, merged;
int n, a, b;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        interval.emplace_back(a, b);
    }
    
    // sort by left endpoints
    sort(interval.begin(), interval.end());
    
    merged.emplace_back(0, -0x3fffffff);
    
    for (auto &cur: interval) {
        auto &right = merged.back().second;
        if (cur.first > right) {
            merged.emplace_back(cur);
        } else {
            right = max(right, cur.second);
        }
    }
    
    printf("%d", merged.size() - 1);
    
    return 0;
}