#include <iostream>
#include <cmath>
using namespace std;

const int len = 23333333;
const double h = 11625907.5798;

// 二分
int main()
{
    int left = 0, right = len / 2;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        double x = 0;
        x -= mid * (1.0 * mid / len) * log2(1.0 * mid / len);
        x -= (len - mid) * (1.0 * (len - mid) / len) * log2(1.0 * (len - mid) / len);
        if (abs(x - h) < 1e-4) // 浮点数大小比较
        {
            cout << mid << endl;
            return 0;
        }
        else if (x > h)
            right = mid;
        else
            left = mid + 1;
    }
    return 0;
}

// 暴力枚举
// int main()
// {
//     for (int i = 1; i < len / 2; ++i) // 0的个数
//     {
//         double x = 0.0;
//         x -= i * (1.0 * i / len) * log2(1.0 * i / len);
//         x -= (len - i) * (1.0 * (len - i) / len) * log2(1.0 * (len - i) / len);
//         if (abs(x - h) < 1e-4) // 浮点数大小比较
//         {
//             cout << i << endl;
//             return 0;
//         }
//     }
//     return 0;
// }