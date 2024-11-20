#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, len;
vector<pair<int, int>> v;

bool judge(int t)
{
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        int tmp = t - v[i].second;
        if (tmp >= 0)
        {
            if (v[i].first - tmp <= pos + 1)
                pos = max(v[i].first + tmp, pos);
            else
                return false;
        }
    }
    return pos >= len;
}

signed main()
{
    cin >> n >> len;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int left = 0, right = 1e10;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (judge(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
    return 0;
}