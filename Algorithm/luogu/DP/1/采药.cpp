#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> a(105);
int dp[105][1005];

int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    // 从前i个物品中挑选, 采药的时间不超过j, 可以采到的草药的最大总价值
    for (int i = 1; i <= m; ++i)
    {
        int x = a[i - 1].first, y = a[i - 1].second;
        for (int j = 1; j <= t; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - x >= 0)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - x] + y);
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}