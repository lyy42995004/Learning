#include <iostream>
#include <unordered_map>
using namespace std;

const int arr[100] = {5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5,
                      8, 6, 1, 8, 3, 0, 3, 7, 9, 2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5,
                      1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1, 2,
                      8, 5, 0, 2, 5, 3, 3};
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 正难则反, 统计哪些天可以由这些数字拼出来, 还可省去去重
int main()
{
    int ans = 0;
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 1; j <= days[i]; ++j)
        {
            // 枚举每个日期
            string s = "2023";
            if (i < 10)
                s += "0";
            s += to_string(i);
            if (j < 10)
                s += "0";
            s += to_string(j);
            int len = 0;
            // 判断是否能拼凑出当前日期
            for (int k = 0; k < 100; ++k)
            {
                if (arr[k] + '0' == s[len])
                    ++len;
                if (len == 8)
                {
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// 暴力枚举 + 哈希
// int main()
// {
//     unordered_map<int, int> hash;
//     int ans = 0;
//     for (int a = 0; a < 100; ++a)
//     {
//         if (arr[a] == 2)
//         {
//             for (int b = a + 1; b < 100; ++b)
//             {
//                 if (arr[b] == 0)
//                 {
//                     for (int c = b + 1; c < 100; ++c)
//                     {
//                         if (arr[c] == 2)
//                         {
//                             for (int d = c + 1; d < 100; ++d)
//                             {
//                                 if (arr[d] == 3)
//                                 {
//                                     for (int e = d + 1; e < 100; ++e)
//                                     {
//                                         for (int f = e + 1; f < 100; ++f)
//                                         {
//                                             int month = 10 * arr[e] + arr[f];
//                                             if (month > 12 || month == 0) // 判断是否合法
//                                                 continue;
//                                             for (int g = f + 1; g < 100; ++g)
//                                             {
//                                                 for (int h = g + 1; h < 100; ++h)
//                                                 {
//                                                     int day = arr[g] * 10 + arr[h];
//                                                     if (day > 31 || day == 0) // 判断是否合法
//                                                         continue;
//                                                     int date = 100 * month + day;
//                                                     if (!hash.count(date) && days[month] >= day) // 查重, 判断日期是否合法
//                                                         ans++;
//                                                     hash[date]++;
//                                                 }
//                                             }
//                                         }
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }