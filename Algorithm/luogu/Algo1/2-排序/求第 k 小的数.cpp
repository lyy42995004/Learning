#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); // 加了不会超时
    cin.tie(0), cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> q;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    while(k--)
        q.pop();
    cout << q.top() << endl;
    return 0;
}

// const int N = 5e6 + 10;
// int a[N];

// // 超时
// int main()
// {
//     ios::sync_with_stdio(0); // 加了不会超时
//     cin.tie(0), cout.tie(0);
//     int n, k;
//     cin >> n >> k;
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];
//     sort(a, a + n);
//     cout << a[k] << endl;
//     return 0;
// }