#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v, tmp;
int n;

// 最大偏移量
bool judge(int x)
{
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        int &l = tmp[i].first;
        int &r = tmp[i].second;
        if (l >= pos)
        {
            int d = l - pos;
            if (d > x)
                return false;
            l = pos, r -= d;
        }
        else // 当l比pos小时，把l尽可能的往右移
        {
            int d = min(pos - l, x);
            l += d, r += d;
        }
        pos = r;
        if (pos >= 2e4)
            return true;
    }
    return false;
}

// 过60%，sort之后不一定可以贪心成功
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({2 * a, 2 * b});
    }
    sort(v.begin(), v.end());
    int left = 0, right = 1e6;
    while (left < right)
    {
        tmp = v;
        int mid = left + (right - left) / 2;
        if (judge(mid))
            right = mid;
        else
            left = mid + 1;
    }
    double ans = left / 2.0;
    cout << ans << endl;
    return 0;
}