#include <iostream>
using namespace std;

const int N = 1000010;

char s[N], p[N];
int ne[N], n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> p >> m >> s;
    
    ne[0] = -1;
    for (int i = 1, j = -1; i < n; ++i) {
        while (~j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) ++j;
        ne[i] = j;
    }
    
    for (int i = 0, j = -1; i < m; ++i) {
        while (~j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) ++j;
        if (j == n - 1) {
            cout << i - j << ' ';
            j = ne[j];
        }
    }
    
    return 0;
}