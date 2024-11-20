#include <bits/stdc++.h>
using namespace std;

int m;
double w0, w;

int main()
{
    cin >> w0 >> w >> m;
    double left = 0.0, right = 3.0;
    while (right - left > 1e-6)
    {
        double mid = (right + left) / 2;
        double sum = 0.0, p = 1 + mid;
        for (int i = 0; i < m; ++i)
            sum += (w / p), p *= (1 + mid);
        if (sum > w0)
            left = mid + 1e-6;
        else
            right = mid;  
    }
    printf("%.1lf\n", left * 100);
    return 0;
}