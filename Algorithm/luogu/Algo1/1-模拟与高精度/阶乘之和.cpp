#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int a[N], c[N];
int la, lc;

void mul(int x)
{
    int tmp[N];
    memset(tmp, 0, sizeof a);
    la = la + (x > 9 ? 2 : 1);
    for (int i = 0; i < la; ++i)
    {
        tmp[i] += a[i] * x;
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    memcpy(a, tmp, sizeof a);
    while(!a[la]) // la为最后一个数的下标
        la--;
}

void add()
{
    int tmp[N];
    memset(tmp, 0, sizeof c);
    for (int i = 0; i < max(lc, la + 1); ++i)
    {
        tmp[i] += c[i] + a[i];
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    memcpy(c, tmp, sizeof c);
    while (c[lc])
        lc++;
}

int main()
{
    int n;
    cin >> n;
    a[0] = 1, la = lc = 1;
    for (int i = 1; i <= n; ++i)
    {
        mul(i); // a = a * i
        add(); // c = a + c
    }
    for (int i = lc - 1; i >= 0; --i) // lc为c存储元素的个数
        cout << c[i];
    cout << endl;
    return 0;
}