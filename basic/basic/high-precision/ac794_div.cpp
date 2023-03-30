#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acwing.com/problem/content/description/796/

vector<int> a, c;
int n, b, r;

void div() {
    for (int i = 0; i < n; ++i) {
        r = r * 10 + a[i];
        c.emplace_back(r / b);
        r %= b;
    }
    // 去除前导0
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) c.pop_back();
}

int main() {
    string sa;
    cin >> sa >> b;
    n = sa.size();
    a.resize(n);
    
    for (int i = 0; i < n; ++i) a[i] = sa[i] - '0';
    
    div();
    
    for (int i = c.size() - 1; i >= 0; --i) printf("%d", c[i]);
    printf("\n%d", r);
    
    return 0;
}