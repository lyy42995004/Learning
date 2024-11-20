#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > vv(n);
    for (int i = 0; i < n; ++i)
    {
        vv[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> vv[i][j];
        }
    }
    vector<vector<int> > s(vv);
    if (m == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    s[i][j] = 1;
                else
                    s[i][j] = 0;
            }
        }
    }
    else
    {
        vector<vector<int> > tmp(vv);
        for (int u = 0; u < m - 1; ++u)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    tmp[i][j] = 0;
                    for (int a = 0; a < n; ++a)
                    {
                        tmp[i][j] += s[i][a] * vv[a][j];
                    }
                }
            }
            s = tmp;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}