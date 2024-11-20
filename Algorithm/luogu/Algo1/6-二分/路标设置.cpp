#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int a[N], l, n, k;

// 判断能否使得x为最小空旷指数
bool judge(int x)
{
    int count = 0;
    for (int i = 1; i < n; ++i)
    {
        int y = a[i] - a[i - 1];
        if (y > x)
            count += (y % x == 0 ? y / x - 1 : y / x);
        if (count > k)
            return false;
    }
    return count <= k;
}

signed main()
{
    cin >> l >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    // left从1开始，有可能judge(0)
    int left = 1, right = l;
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