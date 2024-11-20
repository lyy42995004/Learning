#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, g;

int main()
{
    cin >> n >> g;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = 0;
    int left = 0, right = 0, last = -1;
    while (left < n)
    {
        while (right < n && (a[right] % g == 0 || last < left))
        {
            if (a[right] % g != 0)
                last = right;
            right++;
        }
        if (right - left - 1 > 0)
            ans += right - left - 1;
        left++;
    }
    cout << ans << endl;
    return 0;
}