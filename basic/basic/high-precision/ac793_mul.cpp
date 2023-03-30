#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://www.acwing.com/problem/content/795/

vector<int> a, c;
int b, n;

void mul() {
    if (b == 0) {
        c.push_back(0);
        return;
    }
    
    for (int i = 0, t = 0; i < n || t != 0;) {
        if (i < n) t += a[i++] * b;
        c.emplace_back(t % 10);
        t /= 10;
    }
}

int main() {
    string sa;
    cin >> sa >> b;
    n = sa.size();
    a.resize(n);
    
    for (int i = 0; i < n; ++i) a[n - 1 - i] = sa[i] - '0';
    
    mul();
    
    for (int i = c.size() - 1; i >= 0; --i) printf("%d", c[i]);
    
    return 0;
}