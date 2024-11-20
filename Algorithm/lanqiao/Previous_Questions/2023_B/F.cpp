#include <bits/stdc++.h> // 万能头文件
using namespace std;

int d1y[4] = {0, 0, 1, -1};
int d1x[4] = {1, -1, 0, 0};
int d2x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int d2y[8] = {1, -1, 0, 1, -1, 0, 1, -1};
// sz 每个岛屿的编号，ans 结果， grid 存图
int m, n, sz, ans, grid[55][55];
// check 记录岛屿是否出现过， vis 记录是否对岛屿进行过判断
bool check[1500], vis[55][55];

// 从2开始为每个岛屿标号
void dfs1(int i, int j)
{
    grid[i][j] = sz;
    for (int k = 0; k < 4; ++k)
    {
        int y = i + d1y[k];
        int x = j + d1x[k];
        if (y > 0 && y <= m && x > 0 && x <= n && grid[y][x] == 1)
            dfs1(y, x);
    }
}

// 从(0, 0)边界水, 开始搜索, 能找到的岛屿不是子岛屿
// 如果不增加两边水，当从陆地开始找水时, 需要判断是否是同一块岛屿继续搜索,
// 和遇到其他岛屿停止当前搜索, 两种情况，较为复杂
void dfs2(int i, int j)
{
    for (int k = 0; k < 8; ++k)
    {
        int y = i + d2y[k];
        int x = j + d2x[k];
        if (y >= 0 && y <= m + 1 && x >= 0 && x <= n + 1 && !vis[y][x])
        {
            vis[y][x] = true;
            if (grid[y][x] == 0)
            {
                dfs2(y, x);
            }
            else if (grid[y][x] >= 2 && !check[grid[y][x]])
            {
                check[grid[y][x]] = true;
                ans++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); // 提高cin，cout速率
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0, sz = 2;
        memset(grid, 0, sizeof(grid)); // 初始化
        memset(check, 0, sizeof(check));
        memset(vis, 0, sizeof(vis));
        cin >> m >> n;
        for (int i = 1; i <= m; ++i)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= n; ++j) // 增加两边边界水的情况，存图
                grid[i][j] = s[j - 1] - '0';
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs1(i, j); // 给岛屿标号
                    sz++;
                }
            }
        }
        dfs2(0, 0); // 统计非子岛屿的个数
        cout << ans << endl;
    }
    return 0;
}