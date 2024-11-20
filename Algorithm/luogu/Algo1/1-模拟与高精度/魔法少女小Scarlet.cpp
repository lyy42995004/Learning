#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10;
int a[N][N], tmp[N][N];

void f(int x, int y, int r, int z)
{
    memcpy(tmp, a, sizeof(a));
    if (z == 0)
    {
        for (int i = 1; i <= r; ++i)
        {
            for (int j = -i; j <= i; ++j)
            {
                tmp[x - i][y + j] = a[x - j][y - i];
                tmp[x + i][y + j] = a[x - j][y + i];
                tmp[x + j][y - i] = a[x + i][y + j];
                tmp[x + j][y + i] = a[x - i][y + j];
            }
        }
    }
    else
    {
        for (int i = 1; i <= r; ++i)
        {
            for (int j = -i; j <= i; ++j)
            {
                tmp[x - i][y + j] = a[x + j][y + i];
                tmp[x + i][y + j] = a[x + j][y - i];
                tmp[x + j][y - i] = a[x - i][y - j];
                tmp[x + j][y + i] = a[x + i][y - j];
            }
        }
    }
    memcpy(a, tmp, sizeof(a));
}

int main()
{
    int n, m, num = 1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = num++;
    for (int i = 0; i < m; ++i)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        f(x - 1, y - 1, r, z);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}