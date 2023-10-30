#include <iostream>
#include <vector>
using namespace std;
// https://www.acwing.com/problem/content/description/340/
/*
    n = abcdefg
    分别求出 x 在每一位的出现次数

    eg. 求 x 在位 d 上出现的次数
        1 <= XXXxYYY <= abcdefg
    1) XXX = [000, abc - 1], YYY = [000, 999], 
        a) x = 0 => XXX = [001, abc - 1] => (abc - 1) * 1000
        b) x != 0 => abc * 1000
    2) XXX = abc
        a) d < x, => 0
        b) d = x, YYY = [000, efg], => efg + 1
        c) d > x, YYY = [000, 999], => 1000
*/

int count(int n, int x)
{
    if (!n) return 0;
    int res = 0;
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    
    for (int i = n - 1 - !x; i >= 0; --i) {
        int a = 0, b = 0, t = 1;
        for (int j = n - 1; j > i; --j) a = a * 10  + num[j];
        for (int j = i - 1; j >= 0; --j) b = b * 10 + num[j], t *= 10;
        res += (a - !x) * t;
        if (num[i] == x) res += b + 1;
        else if (num[i] > x) res += t; 
    }
    
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; ++i)
            cout << count(b, i) - count(a - 1, i) << " \n"[i == 9];
    }
    
    return 0;
}