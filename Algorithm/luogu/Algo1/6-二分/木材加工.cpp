#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int a[N];

signed main()
{
    int n, k, maxl = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > maxl)
            maxl = a[i];
    }
    int left = 0, right = maxl;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += a[i] / mid;
        if (sum >= k)
            left = mid;
        else
            right = mid - 1;
    }
    cout << left << endl;
    return 0;
}