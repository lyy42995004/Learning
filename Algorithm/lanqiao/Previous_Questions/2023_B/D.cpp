#include <bits/stdc++.h> // 万能头文件
using namespace std;

int n;
const int N = 10;
// check标记是否进行过能否降落的判断
bool check[N], flag;
// t到达时间，d盘旋时间，l降落时间
int t[N], d[N], l[N];

// u 降落飞机的数量
// time 上一个飞机降落完成的时间，也就是可以开始降落的最早时间
void dfs(int u, int time)
{
    if (u >= n)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!check[i] && time <= t[i] + d[i]) // 未判断过并且可以成功降落
        {
            check[i] = true;
            dfs(u + 1, max(time, t[i]) + l[i]); // 最早能完成降落的时间
            check[i] = false;
        }
    }
}

// 数据量小, dfs暴力枚举
int main()
{
    ios::sync_with_stdio(false); // 提高cin，cout速率
    cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    while (k--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            check[i] = false; // check数组初始化
            cin >> t[i] >> d[i] >> l[i];
        }
        flag = false; // flag初始化
        dfs(0, 0);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}