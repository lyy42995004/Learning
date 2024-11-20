#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
string s;

// 贪心, 每个位置都跟前面的位置进行判断
int main()
{
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1] || s[i] == '?' || s[i - 1] == '?')
        {
            ans++;
            i++; // 跳过下一个位置
        }
    }
    cout << ans << endl;
    return 0;
}

// const int N = 1e6 + 10;
// int dp[N][2];
// string s;

// // DP
// int main()
// {
//     cin >> s;
//     int n = s.size();
//     // 以i位置为结尾, 0表示i位置不进行子串判断, 1进行判断, 出现互不重叠的 00 和 11 子串最多个数
//     dp[0][0] = dp[0][1] = 0;
//     for (int i = 1; i < n; ++i)
//     {
//         dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
//         dp[i][1] = (s[i] == s[i - 1] || s[i - 1] == '?' || s[i] == '?') ? dp[i - 1][0] + 1 : 0;
//     }
//     cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
//     return 0;
// }