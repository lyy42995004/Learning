#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], n, m;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    int p1 = 1, p2 = 1, ans = 0;
    int sum1 = a[p1++], sum2 = b[p2++];
    while (p1 <= n || p2 <= m)
    {
        if (sum1 == sum2)
            sum1 = a[p1++], sum2 = b[p2++];
        else if (sum1 < sum2)
            sum1 += a[p1++], ans++;
        else
            sum2 += b[p2++], ans++;
    }
    cout << ans << endl;
    return 0;
}