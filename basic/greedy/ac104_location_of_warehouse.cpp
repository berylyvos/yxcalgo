#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acwing.com/problem/content/description/106/
// 绝对值不等式
//   |A1 - x| + |A2 - x| + ... + |An - x|
// = (|A1 - x| + |An - x|) + (|A2 - x| + |An-1 - x|) + ...
// >= |An - A1| + |An-1 - A2| + ... 

const int N = 100010;
int a[N], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    sort(a, a + n);
    int res = 0, mid = a[n / 2];
    for (int i = 0; i < n; ++i) res += abs(a[i] - mid);
    
    cout << res;
    return 0;
}