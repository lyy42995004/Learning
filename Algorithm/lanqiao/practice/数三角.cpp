#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 10;
int a[N], b[N], n;
map<pair<int, int>, int> piont;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        piont[{a[i], b[i]}]++;
    }
    int ans = 0;
    // 枚举顶点，判断是否是等腰三角
    for (int i = 0; i < n; ++i)
    {
        // vector<int> 用于所有记录距离相同的点
        unordered_map<int, vector<int>> hash;
        for (int j = 0; j < n; ++j)
        {
            int dis = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
            if (dis)
                hash[dis].push_back(j);
        }
        for (auto h : hash)
        {
            int num = h.second.size();
            ans += num * (num - 1) / 2;
            int del = 0;
            for (auto v : h.second)
            {
                int x = 2 * a[i] - a[v];
                int y = 2 * b[i] - b[v];
                del += piont[{x, y}];
            }
            ans -= del / 2;
        }
    }
    cout << ans << endl;
    return 0;
}

// typedef pair<int, int> pii;
// vector<pii> v;
// int n;

// // 计算两点之间距离
// double f(pii &p1, pii &p2)
// {
//     int a = abs(p1.first - p2.first), b = abs(p1.second - p2.second);
//     return sqrt(a * a + b * b);
// }

// // 判断是否是等腰三角形
// bool judge(pii &p1, pii &p2, pii &p3)
// {
//     // 判断三点是否在一条直线上
//     if ((p1.first == p2.first && p2.first == p3.first) || (p1.second == p2.second && p2.second == p3.second))
//         return false;
//     double a = f(p1, p2), b = f(p2, p3), c = f(p3, p1);
//     return (a == b || b == c || c == a);
// }

// // 暴力，过不了一个
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//     {
//         int x, y;
//         cin >> x >> y;
//         v.push_back({x, y});
//     }
//     int ans = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = i + 1; j < n; ++j)
//         {
//             for (int k = j + 1; k < n; ++k)
//             {
//                 if (judge(v[i], v[j], v[k]))
//                     ans++;
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }