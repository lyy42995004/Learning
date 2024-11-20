#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
// a学校分数线
int a[N];

signed main()
{
    int m, n, sum = 0;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    sort(a, a + m);
    for (int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;
        auto it = lower_bound(a, a + m, b);
        int right = (it != a + m ? *it : 0x3f3f3f3f); // 未找到，是比所有数都大的情况
        int left = (it != a ? *(it - 1) : -0x3f3f3f3f); // 找到第一个数，是比所有数都小的情况
        sum += min(right - b, b - left);
    }
    cout << sum << endl;
    return 0;
}