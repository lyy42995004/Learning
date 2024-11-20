#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
double a[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        a[i] = (l + r) / 2.0;
    }
    sort(a, a + n);
    while(m--)
    {
        int L, R;
        cin >> L >> R;
        int ans = upper_bound(a, a + n, R) - lower_bound(a, a + n, L);
        cout << ans << endl;
    }
    return 0;
}