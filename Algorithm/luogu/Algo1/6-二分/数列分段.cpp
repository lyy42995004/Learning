#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int a[N], n, m;

bool judge(int x)
{
    int sum = 0, count = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > x)
            return false;
        sum += a[i];
        if (sum > x)
            count++, sum = a[i];
        if (count > m)
            return false;
    }
    return true;
}

signed main()
{
    int sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int left = 0, right = sum;
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