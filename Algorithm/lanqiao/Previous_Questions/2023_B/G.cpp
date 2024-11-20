#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
const int N = 5e5 + 10;
int a[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int k, sum = 0, count = 1;
    char c1, c2;
    cin >> k >> s >> c1 >> c2;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == c1)
            a[i] = count++;
        if (s[i] == c2)
        {
            for (int j = i - k + 1; j >= 0; --j)
            {
                if (a[j] != 0)
                {
                    sum += a[j];
                    break;
                }
            }
        }
    }
    cout << sum << '\n';
    return 0;
}

// // // 模拟(过90%)
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     int k, sum = 0;
//     char c1, c2;
//     cin >> k >> s >> c1 >> c2;
//     int n = s.size();
//     // i结束, j开始的区间
//     for (int i = k - 1; i < n; ++i)
//     {
//         if (s[i] == c2)
//         {
//             for (int j = i - k + 1; j >= 0; --j)
//             {
//                 if (s[j] == c1)
//                     a[i]++;
//                 if (a[j] != 0) // 优化后可以过90%
//                 {
//                     for (int u = 1; u < k - 1; ++u) // 从1开始, 自己不再次用判断
//                     {
//                         if (s[j - u] == c1)
//                             a[i]++;
//                     }
//                     a[i] += a[j];
//                     break;
//                 }
//             }
//             sum += a[i];
//         }
//     }
//     cout << sum << '\n';
//     return 0;
// }

// // 模拟(可过部分)
// signed main()
// {
//     int k, sum = 0;
//     char c1, c2;
//     cin >> k >> s >> c1 >> c2;
//     int n = s.size();
//     for (int i = k - 1; i < n; ++i)
//     {
//         int tmp = 0;
//         if (s[i] == c2)
//         {
//             for (int j = 0; j <= i - k + 1; ++j)
//             {
//                 if (s[j] == c1)
//                     tmp++;
//             }
//         }
//         sum += tmp;
//     }
//     cout << sum << '\n';
//     return 0;
// }