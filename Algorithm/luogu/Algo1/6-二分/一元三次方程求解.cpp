#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

double func(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

// 二分
int main()
{
    cin >> a >> b >> c >> d;
    int num = 0;
    for (double i = -100.0; i <= 100; ++i)
    {
        // 整数必须单独算， 因为func(i)和func(i+1)均为结果时，都不会输出
        if (func(i - 1) == 0)
        {
            printf("%.2lf ", i - 1);
            num++;
        }
        if (func(i - 1) * func(i) < 0)
        {
            double left = i - 1, right = i;
            while (right - left > 1e-3)
            {
                double mid = (right + left) / 2;
                if (func(left) * func(mid) < 0)
                    right = mid;
                else
                    left = mid + 0.001;
            }
            printf("%.2lf ", left);
            num++;
        }
        if (num == 3)
            break;
    }
    return 0;
}


// // 暴力
// int main()
// {
//     int num = 0;
//     double a, b, c, d;
//     cin >> a >> b >> c >> d;
//     for (double i = -100.0; i < 100.0; i += 0.001)
//     {
//         double j = i + 0.001;
//         if ((a*i*i*i + b*i*i + c*i + d) * (a*j*j*j + b*j*j + c*j + d) < 0)
//         {
//             printf("%.2lf ", i);
//             num++;
//         }
//         if (num == 3)
//             break;
//     }
//     return 0;
// }