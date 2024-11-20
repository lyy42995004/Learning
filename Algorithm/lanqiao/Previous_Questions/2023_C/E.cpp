#include <bits/stdc++.h>
using namespace std;

// 模拟
int main()
{
    int d;
    cin >> d;
    while (d--)
    {
        string s, t;
        cin >> t >> s;
        int n = s.size(), ans = 0;
        if (s[0] != t[0] || s[n - 1] != t[n - 1])
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i < n - 1; ++i)
        {
            if (s[i] != t[i])
            {
                if (s[i - 1] != s[i] && s[i + 1] != s[i])
                {
                    s[i] = s[i - 1];
                    ans++;
                }
                else
                {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}