#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3;
struct Date
{
    int y, m, d, h, min, s;
} D[N];

bool cmp(Date &d1, Date &d2)
{
    if (d1.m != d2.m)
        return d1.m < d2.m;
    else if (d1.d != d2.d)
        return d1.d < d2.d;
    else if (d1.h != d2.h)
        return d1.h < d2.h;
    else if (d1.min != d2.min)
        return d1.min < d2.min;
    else
        return d1.s < d2.s;
}

signed main()
{
    for (int i = 0; i < 520; ++i)
        scanf("%lld-%lld-%lld %lld:%lld:%lld", &D[i].y, &D[i].m, &D[i].d, &D[i].h, &D[i].min, &D[i].s);
    sort(D, D + 520, cmp);
    const int X = 24 * 3600;
    int sum = 0;
    for (int i = 0; i < 520; i += 2)
    {
        int a = D[i].h * 3600 + D[i].min * 60 + D[i].s;
        int b = D[i + 1].h * 3600 + D[i + 1].min * 60 + D[i + 1].s;
        if (D[i].d == D[i + 1].d)
            sum += b - a;
        else
            sum += X - a + b;
    }
    cout << sum << endl;
    return 0;
}