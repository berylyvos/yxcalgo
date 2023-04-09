#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://www.acwing.com/problem/content/794/

vector<int> a, b, c;
int n, m;

// return a >= b
bool gte() {
    if (n != m) return n > m;
    for (int i = n - 1; i >= 0; --i)
        if (a[i] != b[i]) return a[i] > b[i];
    return true; // a == b
}

void sub(vector<int>& a, vector<int>& b) {
    for (int i = 0, t = 0; i < n; ++i) {
        t += a[i];
        if (i < m) t -= b[i];
        c.emplace_back((t + 10) % 10);
        t = t < 0 ? -1 : 0;
    }
    // 去除前导0
    while (c.size() > 1 && c.back() == 0) c.pop_back();
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string sa, sb;
    cin >> sa >> sb;
    n = sa.size(), m = sb.size();
    a.resize(n), b.resize(m);
    for (int i = 0; i < n; ++i) a[n - 1 - i] = sa[i] - '0';
    for (int i = 0; i < m; ++i) b[m - 1 - i] = sb[i] - '0';
    
    if (gte()) {
        sub(a, b);
    } else {
        swap(n, m);
        sub(b, a);
        cout << '-';
    }
    
    for (int i = c.size() - 1; i >= 0; --i) cout << c[i];
    
    return 0;
}