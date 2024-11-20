#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int a[N][N], dp[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> a[i][j];
    int ans = 0;
    // 以i行j列为结尾最大权重和
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + a[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i - 1][j - 1];
            if (i == n)
                ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}