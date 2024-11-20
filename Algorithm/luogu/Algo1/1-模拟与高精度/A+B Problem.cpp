#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N], b[N], c[N];
int la, lb, lc;

void add()
{
    for (int i = 0; i < lc; ++i)
    {
        c[i] += a[i] + b[i];
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    if (!c[lc])
        lc--;
}

// 高精度加法
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    la = s1.size(), lb = s2.size(), lc = max(la, lb);
    for (int i = 0; i < la; ++i)
        a[i] = s1[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i)
        b[i] = s2[lb - 1 - i] - '0';
    add();
    for (int i = lc; i >= 0; --i)
        cout << c[i];
    cout << endl;
    return 0;
}