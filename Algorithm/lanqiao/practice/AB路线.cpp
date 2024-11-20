#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int a[N][N], dis[N][N][20];
bool st[N][N][20];
int n, m, k;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<array<int, 3>> q;

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = (s[j] != 'A');
    }
    if (a[0][0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0x3f3f3f3f;
    st[0][0][1] = true;
    dis[0][0][1] = 1;
    q.push({0, 0, 1});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int x = t[0], y = t[1], c = t[2];
        int d = dis[x][y][c];
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || st[nx][ny][(d + 1) % k])
                continue;
            if (a[nx][ny] == (d / k) % 2)
            {
                st[nx][ny][(d + 1) % k] = true;
                dis[nx][ny][(d + 1) % k] = d + 1;
                q.push({nx, ny, (d + 1) % k});
            }
        }
    }
    for (int i = 0; i < k; ++i)
        if (dis[n - 1][m - 1][i])
            ans = min(dis[n - 1][m - 1][i], ans);
    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans - 1 << endl;
    return 0;
}