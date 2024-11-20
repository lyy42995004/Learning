#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N], b[N], c[N];
int la, lb, lc;

bool cmp()
{
    if (la != lb)
        return la > lb;
    for (int i = la - 1; i >= 0; --i)
        if (a[i] != b[i])
            return a[i] > b[i];
    return true;
}

void sub()
{
    for (int i = 0; i < la; ++i)
    {
        if (a[i] < b[i])
            a[i + 1]--, c[i] += 10;
        c[i] += a[i] - b[i];
    }
    while (lc && !c[lc])
        lc--;
}

// 高精度减法
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    la = s1.size(), lb = s2.size();
    lc = max(la, lb); // 减时, 也取最大长度
    for (int i = 0; i < la; ++i) // 存储
        a[i] = s1[la - 1 - i] - '0';
    for (int i = 0; i < lb; ++i)
        b[i] = s2[lb - 1 - i] - '0';
    if (!cmp())
        swap(a, b), swap(la, lb), cout << '-'; // 使a大于b
    sub();
    for (int i = lc; i >= 0; --i)
        cout << c[i];
    cout << endl;
    return 0;
}