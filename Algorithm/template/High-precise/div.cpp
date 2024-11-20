#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int a[N], c[N];
int b, la, lc;

void div()
{
    long long r = 0;
    for (int i = la - 1; i >= 0; --i)
    {
        r = r * 10 + a[i];  // 被除数
        c[i] = r / b;       // 商
        r %= b;             // 余数
    }
    while (lc && !c[lc])
        lc--;
}

// 高精度除法
int main()
{
    string s;
    cin >> s >> b;
    lc = la = s.size();
    for (int i = 0; i < la; ++i)
        a[i] = s[la - 1 - i] - '0';
    div();
    for (int i = lc; i >= 0; --i)
        cout << c[i];
    cout << endl;
    return 0;
}