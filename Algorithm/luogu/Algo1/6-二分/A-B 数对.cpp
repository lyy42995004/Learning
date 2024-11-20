#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N], n, c, ans;

// STL
signed main()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        ans += upper_bound(a + i, a + n, a[i] + c) - lower_bound(a + i, a + n, a[i] + c);
    cout << ans << endl;
    return 0;
}

// void find(int i)
// {
//     // 找左端点
//     int left = i, right = n - 1;
//     while (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         if (a[i] + c > a[mid])
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     if (a[left] != a[i] + c)
//         return;
//     int l = left;
//     // 找右端点
//     right = n - 1;
//     while (left < right)
//     {
//         int mid = left + (right - left + 1) / 2;
//         if (a[i] + c < a[mid])
//             right = mid - 1;
//         else
//             left = mid;
//     }
//     ans += (right - l + 1);
// }

// // 二分
// signed main()
// {
//     cin >> n >> c;
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];
//     sort(a, a + n);
//     for (int i = 0; i < n; ++i)
//         find(i);
//     cout << ans << endl;
//     return 0;
// }