#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 5e4 + 10;
int a[N];
int l, n, m;

// 判断是否能使得x为最短跳跃距离时，移除石头能否够
bool judge(int x)
{
    // pos当前位置，count移除石头的个数
    int pos = 0, count = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (a[i] - a[pos] < x)
            count++;
        else
            pos = i;
    }
    return count <= m;        
}

int main()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = l;
    int left = 0, right = l;
    while (left < right)
    {
        // mid最短跳跃距离
        // mid太小距离不够跳到下一个，但取的是最大值，所以取不到
        // mid太大m不够，移不了太多石头
        int mid = left + (right - left + 1) / 2;
        // 判断成立时，继续向右取，因为要的是最大值
        if (judge(mid))
            left = mid;
        // 不成立时，向左取，右边都不可能成立
        else
            right = mid - 1;
    }
    cout << left << endl;
    return 0;
}