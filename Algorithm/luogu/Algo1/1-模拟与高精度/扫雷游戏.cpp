#include <bits/stdc++.h>
using namespace std;

char a[105][105];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

// 扫雷游戏
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '?')
            {
                int count = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '*')
                        count++;
                }
                a[i][j] = count + '0';
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}