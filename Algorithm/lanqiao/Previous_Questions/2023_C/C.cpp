#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, a[N], b[N], c[N], x[N], y[N], z[N];

// 贪心
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    // 可以通过一个函数, 减少下面的重复代码, 并且不用在创建x, y, z数组
    for (int i = 0; i < n; ++i)
    {
        x[i] = a[i] - b[i] - c[i];
        y[i] = b[i] - a[i] - c[i];
        z[i] = c[i] - a[i] - b[i];
    }
    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);
    int sumx = 0, sumy = 0, sumz = 0;
    int retx, rety, retz;
    for (int i = n - 1; i >= 0; --i)
    {
        sumx += x[i];
        if (sumx <= 0)
        {
            retx = n - i - 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        sumy += y[i];
        if (sumy <= 0)
        {
            rety = n - i - 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        sumz += z[i];
        if (sumz <= 0)
        {
            retz = n - i - 1;
            break;
        }
    }
    int ans = max(retx, max(rety, retz));
    if (ans == 0)
        ans = -1;
    cout << ans << '\n';
    return 0;
}

// const int N = 1e5 + 10;
// int a[N], b[N], c[N], ans, n;

// void dfs(int x, int y, int z, int i, int num)
// {
//     if (i >= n)
//         return;
//     if (x + y > z || y + z > x || z + x > y)
//         ans = max(ans, num);
//     dfs(x + a[i], y + b[i], z + c[i], i + 1, num + 1);
//     dfs(x, y, z, i + 1, num);
// }

// //DFS(过不了一个)
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];
//     for (int i = 0; i < n; ++i)
//         cin >> b[i];
//     for (int i = 0; i < n; ++i)
//         cin >> c[i];
//     dfs(0, 0, 0, 0, 0);
//     if (ans == 0)
//         ans = -1;
//     cout << ans << '\n';
//     return 0;
// }