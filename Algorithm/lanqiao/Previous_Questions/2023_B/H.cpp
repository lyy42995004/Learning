#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
const int N = 5e5 + 10;
int a[N], l[N], r[N];

// 优先队列, 链表
signed main()
{
    int n, k;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        q.push({a[i], i});
        l[i] = i - 1;
        r[i] = i + 1;
        if (i == n - 1)
            r[i] = -1;
    }
    while (k)
    {
        pii t = q.top();
        int pos = t.second;
        q.pop();
        if (t.first != a[pos])
        {
            q.push({a[pos], pos});
            continue;
        }
        k--;
        if (l[pos] >= 0)
        {
            a[l[pos]] += t.first;
            r[l[pos]] = r[pos];
        }
        if (r[pos] >= 0)
        {
            a[r[pos]] += t.first;
            l[r[pos]] = l[pos];
        }
        a[pos] = -1;
    }
    for (int i = 0; i < n; ++i)
        if (a[i] != -1)
            cout << a[i] << " ";
    cout << '\n';
    return 0;
}

// const int N = 5e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
// int a[N];

// // 暴力枚举(过部分)
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     int n, k;
//     cin >> n >> k;
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];
//     for (int i = 0; i < k; ++i)
//     {
//         int minj = 0;
//         for (int j = 1; j < n; ++j)
//         {
//             if (a[minj] > a[j])
//                 minj = j;
//         }
//         for (int t = minj + 1; t < n; ++t)
//         {
//             if (a[t] != INF)
//             {
//                 a[t] += a[minj];
//                 break;
//             }
//         }
//         for (int t = minj - 1; t >= 0; --t)
//         {
//             if (a[t] != INF)
//             {
//                 a[t] += a[minj];
//                 break;
//             }
//         }
//         a[minj] = INF;
//     }
//     for (int i = 0; i < n; ++i)
//     {
//         if (a[i] < INF)
//             cout << a[i] << " ";
//     }
//     cout << '\n';
//     return 0;
// }