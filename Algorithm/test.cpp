#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e3 + 10;
int g[N][N];
bool st[N][N][20];
int dis[N][N][20];

int n, m, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs()
{
    for (int p = 0; p < k; p++)
    {
        dis[n - 1][m - 1][p] = INF;
    }
queue<array<int, 3>> q;
q.push({0, 0, 1});
dis[0][0][1] = 1;
st[0][0][1] = true;
while (q.size())
{
    auto t = q.front();
    q.pop();
    int x = t[0], y = t[1], cnt = t[2];
    int d = dis[x][y][cnt];

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nc = (d / k) % 2;
        if (check(nx, ny) && g[nx][ny] == nc && !st[nx][ny][(d + 1) % k])
        {
            st[nx][ny][(d + 1) % k] = true;
            q.push({nx, ny, (d + 1) % k});

            dis[nx][ny][(d + 1) % k] = d + 1;
        }
    }
}

int minv = INF;
for (int i = 0; i < k; i++)
{
    minv = min(minv, dis[n - 1][m - 1][i]);
}
return minv;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            g[i][j] = (s[j] != 'A');
        }
    }

    int res = bfs();
    if (res == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res - 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}