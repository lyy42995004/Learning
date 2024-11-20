#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int arr[N], dp[N][15];
int n;

int get_first(int x)
{
    while (x > 9)
        x /= 10;
    return x;
}

int get_last(int x)
{
    return x % 10;
}

// DP
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    // 以i位置为结尾, 最后一位是j的接龙数列的最小删除数
    // 根据状态表示写出状态转移方程
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            dp[i][j] = dp[i - 1][j] + 1;
            if (j == get_last(arr[i - 1])) // dp表多加了一行，arr下标减一
                dp[i][j] = min(dp[i][j], dp[i - 1][get_first(arr[i - 1])]);
        }
    }
    int ans = INF;
    for (int j = 0; j < 10; ++j)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}

// const int N = 1e5 + 10;
// int arr[N];
// int n, ans;

// int get_first(int x)
// {
//     while (x > 9)
//         x /= 10;
//     return x;
// }

// int get_last(int x)
// {
//     return x % 10;
// }

// // k当前是第几个数，len当前的长度，last前一个数
// void dfs(int k, int len, int last)
// {
//     if (k == n)
//     {
//         ans = max(ans, len);
//         return;
//     }
//     if (n - k + len <= ans) // 剩余的个数 + 当前个数 <= 当前求出的最大个数时, 不需要再判断了
//         return;
//     if (last == -1 || get_last(last) == get_first(arr[k])) // 选
//         dfs(k + 1, len + 1, arr[k]);
//     dfs(k + 1, len, last); // 不选
// }

// // DFS(可过部分)
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//         cin >> arr[i];
//     dfs(0, 0, -1);
//     cout << n - ans << endl;
//     return 0;
// }