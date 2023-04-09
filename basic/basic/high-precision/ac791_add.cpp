#include <iostream>
#include <string>
#include <vector>
using namespace std;
// https://www.acwing.com/problem/content/793/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    
    vector<int> va(n), vb(m), vc;
    for (int i = n - 1; i >= 0; --i) va[i] = a[i] - '0';
    for (int i = m - 1; i >= 0; --i) vb[i] = b[i] - '0';
    
    for (int i = n - 1, j = m - 1, t = 0; i >= 0 || j >= 0 || t != 0;) {
        if (i >= 0) t += va[i--];
        if (j >= 0) t += vb[j--];
        vc.emplace_back(t % 10);
        t /= 10;
    }
    
    for (int i = vc.size() - 1; i >= 0; --i) cout << vc[i];
    
    return 0;
}