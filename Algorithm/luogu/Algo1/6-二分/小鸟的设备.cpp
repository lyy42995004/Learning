#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
double a[N], b[N]; 
int n, p;

// 判断能否在x时间内一直工作
bool judge(double x)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] * x > b[i])
            sum += a[i] * x - b[i];
    }
    // 能充的电是否大于需要的电
    return p * x >= sum;
}

int main()
{    
    double sum = 0;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p)
    {
        cout << "-1" << endl;
        return 0;
    }
    double left = 0, right = 1e10;
    while (right - left > 1e-6)
    {
        double mid = (right + left) / 2;
        if (judge(mid))
            left = mid;
        else
            right = mid;
    }
    cout << left << endl;
    return 0;
}