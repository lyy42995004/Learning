#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

void mul()
{
    for (int i = 0; i < la; ++i)
    {
        for (int j = 0; j < lb; ++j)
        {
            c[i + j] += a[i] * b[j];       // 累加
            c[i + j + 1] += c[i + j] / 10; // 进位
            c[i + j] %= 10;                // 存余
        }
    }
    while (lc && !c[lc]) // c为零时, lc减一
        lc--;
}

// 高精度乘法
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    la = s1.size(), lb = s2.size(), lc = la + lb;
    for (int i = 0; i < la; ++i)
        a[i] = s1[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i)
        b[i] = s2[lb - 1 - i] - '0';
    mul();
    for (int i = lc; i >= 0; --i)
        cout << c[i];
    cout << endl;
    return 0;
}