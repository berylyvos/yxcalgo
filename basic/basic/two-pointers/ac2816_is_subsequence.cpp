#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/description/2818/

const int N = 100010;
int a[N], b[N], n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    
    int i = 0;
    for (int j = 0; j < m; ++j)
        if (a[i] == b[j])
            if (++i == n) {
                printf("Yes");
                return 0;
            }
        
    printf("No");
    
    return 0;
}