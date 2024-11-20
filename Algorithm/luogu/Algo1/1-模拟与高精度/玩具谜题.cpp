#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef pair<int, string> pis;
vector<pis> v(N);

// 玩具谜题
// 按逆时针方向存储
//        1(外) 0(内)
// 1(左)    顺   逆
// 0(右)    逆   顺
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string s;
        int a;
        cin >> a >> s;
        v[i] = {a, s};
    }
    int pos = 0;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a == v[pos].first)
        {
            pos -= b;
            while (pos < 0)
                pos += n;
        }
        else
            pos = (pos + b) % n;
    }
    cout << v[pos].second << endl;
    return 0;
}