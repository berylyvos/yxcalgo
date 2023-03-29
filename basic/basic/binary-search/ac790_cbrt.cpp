#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/792/
// cubic root
int main() {
    double x;
    scanf("%lf", &x);
    
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    
    printf("%lf", r);
    return 0;
}