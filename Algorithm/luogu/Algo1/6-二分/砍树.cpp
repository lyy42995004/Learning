#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int a[N];

// 二分
signed main()
{
    int n, m, left = 0, right = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > right)
            right = a[i];
    }
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] > mid)
                sum += a[i] - mid;
        if (sum >= m)
            left = mid;
        else
            right = mid - 1;
    }
    cout << left << endl;
    return 0;
}

// 模拟
// signed main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];
//     sort(a, a + n);
//     // x统计当前比h大的数的个数
//     int x = 0, i = n - 1, sum = 0;
//     for (int h = a[n - 1]; h >= 0; --h)
//     {
//         while (h < a[i])
//             x++, i--;
//         sum += x;
//         if (sum >= m)
//         {
//             cout << h << endl;
//             return 0;
//         }
//     }
//     return 0;
// }