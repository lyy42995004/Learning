#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], vis[N], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        vis[a[i]]++;
    }
    int n1 = 0, n2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == 1)
            n1++;
        if (vis[i] > 2)
            n2 += vis[i] - 2;
    }
    if (n2 > n1)
        cout << n2 << endl;
    else
        cout << n2 + (n1 - n2) / 2 << endl;
    return 0;
}